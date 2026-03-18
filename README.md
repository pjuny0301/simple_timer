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
혹은 elapsed_time을 끼워넣을 수 있습니다  
  
```cpp
nrx::timer t;
t.start();

/*작업 1*/
auto a = t.elapsed_time<nrx::timer::milliseconds, int>();       // int ms
/*작업 2*/
auto b = t.elapsed_time<nrx::timer::milliseconds, int>();       // int ms
/*작업 3*/
auto c = t.elapsed_time<nrx::timer::milliseconds, int>();       // int ms
/*작업 4*/
auto d = t.elapsed_time<nrx::timer::milliseconds, int>();       // int ms

t.end();
```

end를 호출하면 end - start가 고정됩니다. 실생활에서도 타이머가 멈추면 더이상 증가하지 않기 때문에 직관성을 위해서 이렇게 설계했습니다.  
