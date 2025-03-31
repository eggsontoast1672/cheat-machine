#include "cmac/chess.hpp"

#include <sstream>

namespace CMac {

Piece Piece::from_char(char c) {
  switch (c) {
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
  case 'b':
    return Piece{PieceColor::Black, PieceKind::Bishop};
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
