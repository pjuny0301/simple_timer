#include<iostream>
#include<chrono>
#include<type_traits>
namespace nrx {
        class timer {
        public:
            using clock = std::chrono::steady_clock;

            using nanoseconds = std::chrono::nanoseconds;
            using microseconds = std::chrono::microseconds;
            using milliseconds = std::chrono::milliseconds;
            using seconds = std::chrono::seconds;

        private:
            bool is_running = false;
            clock::time_point point{};
            clock::duration dur{};

        public:
            void start() {
                is_running = true;
                point = clock::now();
            }

            void end() {
                if (is_running) {
                    dur = clock::now() - point;
                    is_running = false;
                }
            }

            template<typename Duration = milliseconds, typename Ret = long long>
            Ret elapsed_time() const {
                auto current = is_running ? (clock::now() - point) : dur;

                using target_duration =
                    std::chrono::duration<Ret, typename Duration::period>;

                return std::chrono::duration_cast<target_duration>(current).count();
            }
        };

}
}
