#include <coroutine>
#include <iostream>

struct Generator {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        int current_value;

        Generator get_return_object() { return Generator{handle_type::from_promise(*this)}; }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }
        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };

    handle_type handle;

    Generator(handle_type h) : handle(h) {}
    ~Generator() { handle.destroy(); }

    int next() {
        handle.resume();
        return handle.done() ? -1 : handle.promise().current_value;
    }
};

Generator counter() {
    for (int i = 0; i < 100; ++i)
        co_yield i;
}

int main() {
    auto gen = counter();
    for (int i = 0; i < 3; ++i) {
        std::cout << gen.next() << '\n';
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << gen.next() << '\n';
    }

    auto gen2 = counter();
    for (int i = 0; i < 9; ++i) {
        std::cout << gen2.next() << '\n';
    }

    return 0;
}

