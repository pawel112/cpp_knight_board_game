#ifndef TILE_H
#define TILE_H

#include <QLabel>

class tile: public QLabel
{
private:
    int tile_color;
    int piece;
    int piece_color;
    int row;
    int col;
    int tile_num;
    char piece_name;

public:
    tile (QWidget* parent=0, Qt::WindowFlags f=0): QLabel(parent, f) {}
    tile (const QString& text, QWidget* parent=0, Qt::WindowFlags f=0): QLabel(text, parent, f) {}

    int get_tile_color() { return tile_color; }
    int get_piece() { return piece; }
    int get_piece_color() { return piece_color; }
    int get_row() { return row; }
    int get_col() { return col; }
    int get_tile_num() { return tile_num; }
    char get_piece_name() { return piece_name; }

    void set_tile_color (int tileColor) { this->tile_color = tileColor; }
    void set_piece (int piece) { this->piece = piece; }
    void set_piece_color (int pieceColor) { this->piece_color = pieceColor; }
    void set_row (int row) { this->row = row; }
    void set_col (int col) { this->col = col; }
    void set_tile_num (int tileNum) { this->tile_num = tileNum; }
    void set_piece_name (char pieceName) { this->piece_name = pieceName; }

    void mousePressEvent (QMouseEvent *event);
    void display (char elem);
    void tile_display();
};

#endif
