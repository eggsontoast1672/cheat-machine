#include "cmac/chess.hpp"

#include <sstream>

namespace CMac {

Piece Piece::from_char(char c) {
  switch (c) {
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'k':
    return Piece{PieceColor::Black, PieceKind::King};
  case 'n':
    return Piece{PieceColor::Black, PieceKind::Knight};
  case 'p':
    return Piece{PieceColor::Black, PieceKind::Pawn};
  case 'q':
    return Piece{PieceColor::Black, PieceKind::Queen};
  case 'r':
    return Piece{PieceColor::Black, PieceKind::Rook};
  case 'B':
    return Piece{PieceColor::White, PieceKind::Bishop};
  case 'K':
    return Piece{PieceColor::White, PieceKind::King};
  case 'N':
    return Piece{PieceColor::White, PieceKind::Knight};
  case 'P':
    return Piece{PieceColor::White, PieceKind::Pawn};
  case 'Q':
    return Piece{PieceColor::White, PieceKind::Queen};
  case 'R':
    return Piece{PieceColor::White, PieceKind::Rook};
  default:
    throw std::runtime_error{"Piece::from_char: invalid character"};
  }
}

Board::Board(const std::string &fen) {
  std::istringstream stream{fen};

  // Pieces
  std::string pieces;
  stream >> pieces;
  std::istringstream pieces_stream{pieces};
  std::size_t i = 0;
  for (std::string rank; std::getline(pieces_stream, rank, '/');) {
    for (char c : rank) {
      Piece piece = Piece::from_char(c);
    }
  }
}

} // namespace CMac
