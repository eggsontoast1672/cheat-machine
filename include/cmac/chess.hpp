#pragma once

#include <array>
#include <cstdint>
#include <optional>
#include <string>

namespace CMac {

enum class PieceColor { Black, White };
enum class PieceKind { Bishop, King, Knight, Pawn, Queen, Rook };

struct Piece {
  PieceColor color;
  PieceKind kind;

  static Piece from_char(char c);
};

struct CastlingRights {
  bool white_king;
  bool white_queen;
  bool black_king;
  bool black_queen;
};

class Board {
public:
  Board(const std::string &fen);

  std::string as_fen() const;

private:
  std::array<std::optional<Piece>, 64> m_pieces; // m_pieces[0] is a8
  CastlingRights m_castling_rights;
  PieceColor m_side_to_move;
  std::size_t m_en_passant_target;
  std::uint8_t m_halfmove_clock;
  std::uint8_t m_fullmove_counter;
};

} // namespace CMac
