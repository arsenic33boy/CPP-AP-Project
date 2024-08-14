
#include <iostream>
#include <vector>
#include <memory>

// کلاس شکل با خاصیت چگالی
class Shape {
public:
    double volume;
    double density;

    Shape(double vol, double dens) : volume(vol), density(dens) {}

    // محاسبه جرم
    double mass() const {
        return volume * density;
    }
};

// کلاس دستگاه
class Device {
private:
    std::vector<std::shared_ptr<Shape>> shapes;
    std::vector<std::shared_ptr<Device>> devices;

public:
    // افزودن یک شکل به دستگاه
    void addShape(std::shared_ptr<Shape> shape) {
        shapes.push_back(shape);
    }

    // افزودن یک دستگاه به دستگاه
    void addDevice(std::shared_ptr<Device> device) {
        devices.push_back(device);
    }

    // محاسبه حجم کل دستگاه
    double evalVolume() const {
        double totalVolume = 0;
        for (const auto& shape : shapes) {
            totalVolume += shape->volume;
        }
        for (const auto& device : devices) {
            totalVolume += device->evalVolume();
        }
        return totalVolume;
    }

    // محاسبه جرم کل دستگاه
    double evalMass() const {
        double totalMass = 0;
        for (const auto& shape : shapes) {
            totalMass += shape->mass();
        }
        for (const auto& device : devices) {
            totalMass += device->evalMass();
        }
        return totalMass;
    }

    // محاسبه سطح کل دستگاه (فرض می‌کنیم شکل‌ها دارای سطح مشخصی هستند)
    double evalSurface() const {
        // پیاده‌سازی مشابه evalVolume و evalMass
        double totalSurface = 0;
        for (const auto& shape : shapes) {
            totalSurface += shape->volume; // فرض: سطح برابر با حجم است
        }
        for (const auto& device : devices) {
            totalSurface += device->evalSurface();
        }
        return totalSurface;
    }
};

int main() {
    // ایجاد اشکال
    auto shape1 = std::make_shared<Shape>(10.0, 2.5);
    auto shape2 = std::make_shared<Shape>(20.0, 1.5);

    // ایجاد دستگاه‌ها
    auto device1 = std::make_shared<Device>();
    auto device2 = std::make_shared<Device>();

    // افزودن اشکال به دستگاه‌ها
    device1->addShape(shape1);
    device2->addShape(shape2);

    // افزودن دستگاه‌ها به دستگاه اصلی
    auto mainDevice = std::make_shared<Device>();
    mainDevice->addDevice(device1);
    mainDevice->addDevice(device2);

    // محاسبه و نمایش مقادیر
    std::cout << "Total Volume: " << mainDevice->evalVolume() << std::endl;
    std::cout << "Total Mass: " << mainDevice->evalMass() << std::endl;
    std::cout << "Total Surface: " << mainDevice->evalSurface() << std::endl;

    return 0;
}