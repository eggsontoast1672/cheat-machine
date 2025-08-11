use raylib::prelude::*;

const SCREEN_WIDTH: i32 = 800;
const SCREEN_HEIGHT: i32 = 600;
const CELL_WIDTH: f32 = SCREEN_WIDTH as f32 / 8.0;
const CELL_HEIGHT: f32 = SCREEN_HEIGHT as f32 / 8.0;

fn draw_board(d: &mut RaylibDrawHandle) {
    for y in 0..8 {
        for x in 0..8 {
            let color = if (x + y) % 2 == 0 {
                Color::RED
            } else {
                Color::BLUE
            };

            d.draw_rectangle_rec(
                Rectangle {
                    x: x as f32 * CELL_WIDTH,
                    y: y as f32 * CELL_HEIGHT,
                    width: CELL_WIDTH,
                    height: CELL_HEIGHT,
                },
                color,
            );
        }
    }
}

fn main() {
    let (mut rl, thread) = raylib::init()
        .size(SCREEN_WIDTH, SCREEN_HEIGHT)
        .title("Cheat Machine")
        .build();

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);
        d.clear_background(Color::BLACK);
        draw_board(&mut d);
    }
}
