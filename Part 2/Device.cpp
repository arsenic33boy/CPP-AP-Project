#include <iostream>
#include <vector>

class Shape {
protected:
    double density;

public:
    Shape(double dens) : density(dens) {}

    virtual double EvalVolume() const = 0;
    virtual double EvalSurface() const = 0;

    double EvalMass() const {
        return density * EvalVolume();
    }

    void setDensity(double dens) {
        density = dens;
    }

    virtual ~Shape() = default;
};

class Cube : public Shape {
private:
    double side;

public:
    Cube(double sideLength, double dens) : Shape(dens), side(sideLength) {}

    double EvalVolume() const override {
        return side * side * side;
    }

    double EvalSurface() const override {
        return 6 * side * side;
    }

    void setSide(double sideLength) {
        side = sideLength;
    }

    void setDensity(double dens) { 
        density = dens;
    }
};

class Sphere : public Shape {
private:
    double radius;

public:
    Sphere(double rad, double dens) : Shape(dens), radius(rad) {}

    double EvalVolume() const override {
        return (4.0 / 3.0) * 3.141592653589793 * radius * radius * radius;
    }

    double EvalSurface() const override {
        return 4 * 3.141592653589793 * radius * radius;
    }

    void setRadius(double rad) {
        radius = rad;
    }

    void setDensity(double dens) {
        density = dens; 
    }
};

class Device {
private:
    std::vector<Shape*> shapes;
    std::vector<Device*> devices;

public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void addDevice(Device* device) {
        devices.push_back(device);
    }

    double EvalVolume() const {
        double totalVolume = 0;
        for (const auto& shape : shapes) {
            totalVolume += shape->EvalVolume();
        }
        for (const auto& dev : devices) {
            totalVolume += dev->EvalVolume();
        }
        return totalVolume;
    }

    double EvalSurface() const {
        double totalSurface = 0;
        for (const auto& shape : shapes) {
            totalSurface += shape->EvalSurface();
        }
        for (const auto& dev : devices) {
            totalSurface += dev->EvalSurface();
        }
        return totalSurface;
    }

    double EvalMass() const {
        double totalMass = 0;
        for (const auto& shape : shapes) {
            totalMass += shape->EvalMass();
        }
        for (const auto& dev : devices) {
            totalMass += dev->EvalMass();
        }
        return totalMass;
    }
};

int main() {
    Cube cube(3.0, 2.5);
    Sphere sphere(2.0, 1.5);

    Device device1;
    Device device2;
    device1.addShape(&cube);
    device2.addShape(&sphere);

    Device mainDevice;
    mainDevice.addDevice(&device1);
    mainDevice.addDevice(&device2);

    std::cout << "Total Volume: " << mainDevice.EvalVolume() << std::endl;
    std::cout << "Total Mass: " << mainDevice.EvalMass() << std::endl;
    std::cout << "Total Surface: " << mainDevice.EvalSurface() << std::endl;

    return 0;
}
