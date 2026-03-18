# simple_timer  
## 기능  
간단한 성능측정용 타이머입니다. 성능측정에 자주 사용되는 std::chrono::steady_clock을 사용했습니다.

## 사용법  
```cpp
nrx::timer t;  
t.start();

/* 작업 */

t.end();

auto a = t.elapsed_time<nrx::timer::milliseconds, int>();       // int ms
auto b = t.elapsed_time<nrx::timer::microseconds, long long>(); // long long us
auto c = t.elapsed_time<nrx::timer::milliseconds, double>();    // double ms
auto d = t.elapsed_time<nrx::timer::seconds, double>();         // double s
```  

```cpp  
```  

```cpp  
```  
