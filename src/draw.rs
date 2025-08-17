use crate::assets::AssetCache;
use macroquad::prelude::*;

const CELL_COLOR_LIGHT: Color = Color::from_rgba(0xed, 0xd6, 0xb0, 0xff);
const CELL_COLOR_DARK: Color = Color::from_rgba(0xb8, 0x87, 0x62, 0xff);

fn compute_cell_size() -> Vec2 {
    let width = screen_width();
    let height = screen_height();
    Vec2 {
        x: width / 8.0,
        y: height / 8.0,
    }
}

/// Draw the board background.
///
/// This function draws the checkerboard pattern behind all of the pieces. It
/// returns the current cell dimensions so that they only have to be computed
/// once per frame.
fn board_background(cell_size: Vec2) {
    for y in 0..8 {
        for x in 0..8 {
            let cell_color = if (x + y) % 2 == 0 {
                CELL_COLOR_LIGHT
            } else {
                CELL_COLOR_DARK
            };

            draw_rectangle(
                x as f32 * cell_size.x,
                y as f32 * cell_size.y,
                cell_size.x,
                cell_size.y,
                cell_color,
            );
        }
    }
}

fn square_position(square: chess::Square, cell_size: Vec2) -> Vec2 {
    // Assume white POV for now.

    let index = square.to_index();
    let x = index % 8;
    let y = (64 - index - 1) / 8;
    Vec2 {
        x: x as f32 * cell_size.x,
        y: y as f32 * cell_size.y,
    }
}

/// Draw a chess board to the screen.
///
/// This function renders the current state of the chess board to the screen. It
/// should be noted that this function will load assets as it needs them, which
/// is why it requires a reference to the asset cache.
pub async fn board(b: &chess::Board, cache: &mut AssetCache) {
    let cell_size = compute_cell_size();
    let params = DrawTextureParams {
        dest_size: Some(cell_size),
        ..Default::default()
    };

    board_background(cell_size);

    for i in 0..64 {
        // SAFETY: The index i is guaranteed to be within the range [0, 64),
        // which is the valid range for the u8 accepted by Square::new.
        let square = unsafe { chess::Square::new(i) };
        let maybe_color = b.color_on(square);
        let maybe_piece = b.piece_on(square);
        if let (Some(color), Some(piece)) = (maybe_color, maybe_piece) {
            let texture = cache.get(color, piece).await;
            let position = square_position(square, cell_size);
            draw_texture_ex(texture, position.x, position.y, WHITE, params.clone());
        }
    }
}
