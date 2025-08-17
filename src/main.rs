#![deny(missing_docs)]

//! This program is a tool to help win chess games against bots. The idea is
//! that you run this program while playing a bot game to figure out what moves
//! to play. If your bot opponent is worse at chess than Stockfish (likely),
//! then you will win the game! It's very fun.

use assets::AssetCache;
use macroquad::prelude::*;

mod assets;
mod draw;

fn window_conf() -> Conf {
    Conf {
        window_title: String::from("Cheat Machine"),
        window_width: 800,
        window_height: 800,
        sample_count: 4,
        ..Default::default()
    }
}

#[macroquad::main(window_conf)]
async fn main() {
    let mut cache = AssetCache::new();
    let b = chess::Board::default();

    loop {
        draw::board(&b, &mut cache).await;
        next_frame().await;
    }
}
