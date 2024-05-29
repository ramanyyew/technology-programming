#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES

// Абстрактный класс "Точка"
class Point {
public:
    virtual void draw() const = 0;
    virtual void erase() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void rotate(double angle, double cx, double cy) = 0;
    virtual ~Point() {}
};

// Класс "Линия"
class Line {
private:
    double x1, y1, x2, y2;
public:
    Line(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    // Остальные методы класса
};

// Класс "Прямоугольник"
class Rectangle : public Point {
protected:
    double x, y, width, height;
public:
    Rectangle(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}
    void draw() const override {
        std::cout << "Drawing Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
    }
    void erase() const override {
        std::cout << "Erasing Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
    }
    void move(double dx, double dy) override {
        x += dx;
        y += dy;
    }
    void rotate(double angle, double cx, double cy) override {
        double radians = angle * 3.14 / 180;
        double nx = cos(radians) * (x - cx) - sin(radians) * (y - cy) + cx;
        double ny = sin(radians) * (x - cx) + cos(radians) * (y - cy) + cy;
        x = nx;
        y = ny;
        std::cout << "Rotating Rectangle to new center at (" << x << ", " << y << ") with unchanged dimensions\n";
    }
};

// Класс "Параллелограмм"
class Parallelogram : public Rectangle {
public:
    Parallelogram(double x, double y, double width, double height) : Rectangle(x, y, width, height) {}
    void draw() const override {
        std::cout << "Drawing Parallelogram at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
    }
    void erase() const override {
        std::cout << "Erasing Parallelogram at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
    }
    void move(double dx, double dy) override {
        x += dx;
        y += dy;
    }
    void rotate(double angle, double cx, double cy) override {
        Rectangle::rotate(angle, cx, cy);
        std::cout << "Rotating Parallelogram to new center at (" << x << ", " << y << ") with unchanged dimensions\n";
    }
};

// Класс "Ромб"
class Rhombus : public Parallelogram {
public:
    Rhombus(double x, double y, double d1, double d2) : Parallelogram(x, y, d1, d2) {}
    void draw() const override {
        std::cout << "Drawing Rhombus at (" << x << ", " << y << ") with diagonal 1 " << width << " and diagonal 2 " << height << "\n";
    }
    void erase() const override {
        std::cout << "Erasing Rhombus at (" << x << ", " << y << ") with diagonal 1 " << width << " and diagonal 2 " << height << "\n";
    }
    void move(double dx, double dy) override {
        Parallelogram::move(dx, dy);
    }
    void rotate(double angle, double cx, double cy) override {
        Parallelogram::rotate(angle, cx, cy);
        std::cout << "Rotating Rhombus to new center at (" << x << ", " << y << ") with unchanged dimensions\n";
    }
};

// Класс "Квадрат" с виртуальным наследованием
class Square : virtual public Parallelogram {
public:
    Square(double x, double y, double side) : Parallelogram(x, y, side, side) {}
    void draw() const override {
        std::cout << "Drawing Square at (" << x << ", " << y << ") with side " << width << "\n";
    }
    void erase() const override {
        std::cout << "Erasing Square at (" << x << ", " << y << ") with side " << width << "\n";
    }
    void move(double dx, double dy) override {
        Parallelogram::move(dx, dy);
    }
    void rotate(double angle, double cx, double cy) override {
        Parallelogram::rotate(angle, cx, cy);
        std::cout << "Rotating Square to new center at (" << x << ", " << y << ") with unchanged dimensions\n";
    }
};

int main() {
    Rectangle rect(10, 10, 20, 10);
    Square square(20, 20, 30);
    Rhombus rhombus(30, 30, 40, 20);

    rect.draw();
    square.draw();
    rhombus.draw();

    rect.erase();
    square.erase();
    rhombus.erase();

    rect.move(1, 1);
    square.move(1, 1);
    rhombus.move(1, 1);

    rect.rotate(45, 15, 15);
    square.rotate(45, 25, 25);
    rhombus.rotate(45, 35, 35);

    return 0;
}