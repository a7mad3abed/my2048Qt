#ifndef CELL_H
#define CELL_H


class Cell {
public:
    Cell();
    ~Cell();
    int value()const { return mValue; }
    void setValue(int val);
    bool isFree() const;
    void setFree(bool);
private:
    int mValue;
    bool mFree;
};

#endif // CELL_H
