use macroquad::prelude::*;
use std::collections::HashMap;

fn color_to_string(color: chess::Color) -> &'static str {
    match color {
        chess::Color::Black => "black",
        chess::Color::White => "white",
    }
}

fn piece_to_string(piece: chess::Piece) -> &'static str {
    match piece {
        chess::Piece::Bishop => "bishop",
        chess::Piece::King => "king",
        chess::Piece::Knight => "knight",
        chess::Piece::Pawn => "pawn",
        chess::Piece::Queen => "queen",
        chess::Piece::Rook => "rook",
    }
}

fn piece_info_to_path(color: chess::Color, piece: chess::Piece) -> String {
    let color_string = color_to_string(color);
    let piece_string = piece_to_string(piece);
    format!("assets/{}-{}.png", color_string, piece_string)
}

type Key = (chess::Color, chess::Piece);

pub struct AssetCache {
    assets: HashMap<Key, Texture2D>,
}

impl AssetCache {
    pub fn new() -> Self {
        Self {
            assets: HashMap::new(),
        }
    }

    pub async fn get(&mut self, color: chess::Color, piece: chess::Piece) -> &Texture2D {
        let key = (color, piece);

        // We would rather use the get() method on the hash map and mattern match on the return
        // value, but that gives us lifetime issues.
        if !self.assets.contains_key(&key) {
            let path = piece_info_to_path(color, piece);
            let texture = load_texture(&path).await.unwrap();
            self.assets.insert((color, piece), texture);
        }

        &self.assets[&key]
    }
}
