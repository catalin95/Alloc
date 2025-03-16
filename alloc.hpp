#pragma once

#include <cstdio>

namespace allocator
{
template<typename Type>
class Tracker
{
public:
    Tracker() = default;
    Tracker(const Type& resource) { puts("Parameterized constructor is being invoked"); }
    Tracker(const Tracker<Type>& other) { puts("Copy constructor is being invoked"); }
    Tracker(Tracker<Type>&& other) noexcept { puts("Move constructor is being invoked"); }

    auto operator=(const Tracker<Type>& other) -> Tracker<Type>& { puts("Copy assignment operator is being invoked"); return *this; }
    auto operator=(Tracker<Type>&& other) noexcept -> Tracker<Type>& { puts("Move assignment operator is being invoked"); return *this; }

    ~Tracker() { puts("Destructor is being invoked"); }
};
}
