class Row
{
    size_t columns_;
    int *row_;

public:
    Row(int *matrix, size_t columns);

    int &operator [](size_t j);

    const int &operator [](size_t j) const;
};

class Matrix
{
private:
    size_t rows_;
    size_t columns_;
    int **matrix_;

public:
    Matrix(size_t rows, size_t columns);

    Matrix(const Matrix &m);

    Row operator [](size_t i);

    const Row operator [](size_t i) const;

    size_t getRows() const;

    size_t getColumns() const;

    Matrix &operator =(const Matrix m);

    Matrix &operator *=(int a);

    Matrix operator +(Matrix &m) const;

    bool operator ==(Matrix &m) const;

    bool operator !=(Matrix &m) const;

    friend std::ostream &operator <<(std::ostream &oss, Matrix &m);

    ~Matrix();
};

std::ostream &operator <<(std::ostream &os, Matrix &m);
