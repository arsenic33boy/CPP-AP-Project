#include "Vector.h"
#include "PointerVector.h"

int main() {
    CustomVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.insert(1, 4);
    //vec.remove(2);

    for (size_t i = 0; i < vec.get_size(); ++i) {
        std::cout << vec[i] << " ";
    }

    std::cout << '\n';

    // افزودن عناصر به وکتور
    for (int i = 0; i < 100; ++i) {
        vec.insert(i, i);
    }

    // زمان سنجی عملیات درج
    std::clock_t startInsert = clock();
    vec.insert(50, 999);
    std::clock_t endInsert = clock();
    std::cout << "Insert operation took: " << 1000.0 * (endInsert - startInsert) / CLOCKS_PER_SEC << " clock cycles." << std::endl;

    // زمان سنجی عملیات حذف
    std::clock_t startRemove = clock();
    vec.remove(50);
    std::clock_t endRemove = clock();
    std::cout << "Remove operation took: " << 1000.0 * (endRemove - startRemove) / CLOCKS_PER_SEC << " clock cycles." << std::endl;




    return 0;
}