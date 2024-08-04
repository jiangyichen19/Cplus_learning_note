
# 目录
- [exp2:指针的高级操作](#exp2:指针的高级操作)
- [exp3:常见的内存泄漏问题](#exp3:常见的内存泄漏问题)
<!-- - [exp2:指针的高级操作](#) -->





# exp1:位操作学习

# exp2:指针的高级操作

当然可以！在C和C++中，动态内存管理是非常重要的技能之一。下面是一份关于C++/C中内存分配与回收的教程，包括常用的指令集。

### 动态内存分配与回收

#### 1. 动态内存分配
在C和C++中，动态内存分配允许程序在运行时根据需要分配和释放内存。这通常通过以下函数完成：

- **malloc()**：分配指定大小的内存块。
- **calloc()**：分配指定大小的内存块并将其初始化为零。
- **realloc()**：重新分配已分配的内存块，可以扩大或缩小其大小。
- **new**：C++ 中的运算符，用于分配内存并调用构造函数。

#### 2. 动态内存释放
释放动态分配的内存同样重要，以避免内存泄漏。这通常通过以下函数完成：

- **free()**：释放之前通过 malloc/calloc/realloc 分配的内存。
- **delete**：C++ 中的运算符，用于释放由 new 分配的内存并调用析构函数。

#### 3. 示例代码
下面是一些基本的示例代码，展示如何使用这些函数：

##### 3.1 使用 malloc 和 free
```cpp
#include <iostream>
#include <cstdlib> // 包含 malloc 和 free 函数

int main() {
    int *p = nullptr;
    p = static_cast<int*>(malloc(sizeof(int))); // 分配内存
    if (p == nullptr) {
        std::cerr << "Memory allocation failed." << std::endl;
        return 1;
    }

    *p = 42; // 使用分配的内存
    std::cout << "Value: " << *p << std::endl;

    free(p); // 释放内存
    p = nullptr; // 防止悬挂指针

    return 0;
}
```

##### 3.2 使用 calloc 和 free
```cpp
#include <iostream>
#include <cstdlib>

int main() {
    int *p = nullptr;
    p = static_cast<int*>(calloc(1, sizeof(int))); // 分配并初始化内存
    if (p == nullptr) {
        std::cerr << "Memory allocation failed." << std::endl;
        return 1;
    }

    *p = 42; // 使用分配的内存
    std::cout << "Value: " << *p << std::endl;

    free(p); // 释放内存
    p = nullptr; // 防止悬挂指针

    return 0;
}
```

##### 3.3 使用 realloc 和 free
```cpp
#include <iostream>
#include <cstdlib>

int main() {
    int *p = nullptr;
    p = static_cast<int*>(malloc(1 * sizeof(int)));
    if (p == nullptr) {
        std::cerr << "Memory allocation failed." << std::endl;
        return 1;
    }

    *p = 42; // 使用分配的内存
    std::cout << "Initial value: " << *p << std::endl;

    p = static_cast<int*>(realloc(p, 2 * sizeof(int)));
    if (p == nullptr) {
        std::cerr << "Memory reallocation failed." << std::endl;
        return 1;
    }

    p[1] = 56; // 使用重新分配的内存
    std::cout << "Second value: " << p[1] << std::endl;

    free(p); // 释放内存
    p = nullptr; // 防止悬挂指针

    return 0;
}
```

##### 3.4 使用 new 和 delete
```cpp
#include <iostream>

int main() {
    int *p = nullptr;
    p = new int; // 分配内存
    if (p == nullptr) {
        std::cerr << "Memory allocation failed." << std::endl;
        return 1;
    }

    *p = 42; // 使用分配的内存
    std::cout << "Value: " << *p << std::endl;

    delete p; // 释放内存
    p = nullptr; // 防止悬挂指针

    return 0;
}
```

#### 4. 最佳实践
- **检查分配失败**：总是检查内存分配是否成功，如果分配失败，应该采取适当的措施，如返回错误或清理资源。
- **避免悬挂指针**：释放内存后，将指针设置为 `nullptr` 以避免悬挂指针。
- **使用智能指针**：在C++中推荐使用智能指针（如 `std::unique_ptr`, `std::shared_ptr`）来自动管理内存，减少内存泄漏的风险。
- **资源管理类**：考虑使用RAII(Resource Acquisition Is Initialization)风格的类来管理资源，确保资源在对象生命周期结束时自动释放。

#### 5. 智能指针示例
```cpp
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> p(new int); // 使用智能指针
    *p = 42; // 使用分配的内存
    std::cout << "Value: " << *p << std::endl;

    // 内存会在 p 走出作用域时自动释放

    return 0;
}
```

### 总结
动态内存管理是C和C++编程中的一项重要技能。正确地使用动态内存分配和释放函数可以避免内存泄漏和其他潜在的问题。在C++中，尽量使用智能指针来简化内存管理。

希望这份教程对你有所帮助！如果你有任何具体问题或需要进一步的解释，请随时提问。

# exp3 常见的内存泄漏问题