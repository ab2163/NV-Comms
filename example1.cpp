#include <thread>
#include <stdexec/execution.hpp>
#include <exec/static_thread_pool.hpp>
#include <iostream>

int main(void){
  unsigned int num_threads = std::thread::hardware_concurrency();
  if(num_threads == 0) {
    std::cerr << "Unable to determine thread pool size.\n";
    std::exit(EXIT_FAILURE);
  }
  exec::static_thread_pool pool(num_threads);
  auto sched = pool.get_scheduler();
  
  #define ARR_SZ 10 

  static int count[ARR_SZ];
  
  for(int ind = 0; ind < ARR_SZ; ind++){
    count[ind] = 0;
  }

  stdexec::sender auto mysender = stdexec::schedule(sched)
  | stdexec::bulk(stdexec::par_unseq, ARR_SZ, [&](int ind){ count[ind]++; })
  | stdexec::then([&](){ for(int ind = 0; ind < ARR_SZ; ind++){ std::cout << count[ind] << " "; }})
  | stdexec::then([](){ std::cout << "\n"; })
  | stdexec::bulk(stdexec::par_unseq, ARR_SZ, [&](int ind){ count[ind]++; })
  | stdexec::then([&](){ for(int ind = 0; ind < ARR_SZ; ind++){ std::cout << count[ind] << " "; }})
  | stdexec::then([](){ std::cout << "\n"; })
  | stdexec::bulk(stdexec::par_unseq, ARR_SZ, [&](int ind){ count[ind]++; })
  | stdexec::then([&](){ for(int ind = 0; ind < ARR_SZ; ind++){ std::cout << count[ind] << " "; }})
  | stdexec::then([](){ std::cout << "\n"; })
  | stdexec::bulk(stdexec::par_unseq, ARR_SZ, [&](int ind){ count[ind]++; })
  | stdexec::then([&](){ for(int ind = 0; ind < ARR_SZ; ind++){ std::cout << count[ind] << " "; }})
  | stdexec::then([](){ std::cout << "\n"; })
  | stdexec::bulk(stdexec::par_unseq, ARR_SZ, [&](int ind){ count[ind]++; })
  | stdexec::then([&](){ for(int ind = 0; ind < ARR_SZ; ind++){ std::cout << count[ind] << " "; }})
  | stdexec::then([](){ std::cout << "\n"; })
  | stdexec::bulk(stdexec::par_unseq, ARR_SZ, [&](int ind){ count[ind]++; })
  | stdexec::then([&](){ for(int ind = 0; ind < ARR_SZ; ind++){ std::cout << count[ind] << " "; }})
  | stdexec::then([](){ std::cout << "\n"; })
  | stdexec::bulk(stdexec::par_unseq, ARR_SZ, [&](int ind){ count[ind]++; })
  | stdexec::then([&](){ for(int ind = 0; ind < ARR_SZ; ind++){ std::cout << count[ind] << " "; }})
  | stdexec::then([](){ std::cout << "\n"; })
  | stdexec::bulk(stdexec::par_unseq, ARR_SZ, [&](int ind){ count[ind]++; })
  | stdexec::then([&](){ for(int ind = 0; ind < ARR_SZ; ind++){ std::cout << count[ind] << " "; }})
  | stdexec::then([](){ std::cout << "\n"; })
  | stdexec::bulk(stdexec::par_unseq, ARR_SZ, [&](int ind){ count[ind]++; })
  | stdexec::then([&](){ for(int ind = 0; ind < ARR_SZ; ind++){ std::cout << count[ind] << " "; }})
  | stdexec::then([](){ std::cout << "\n"; })
  | stdexec::bulk(stdexec::par_unseq, ARR_SZ, [&](int ind){ count[ind]++; })
  | stdexec::then([&](){ for(int ind = 0; ind < ARR_SZ; ind++){ std::cout << count[ind] << " "; }})
  | stdexec::then([](){ std::cout << "\n"; });
  
  stdexec::sync_wait(mysender);
  
  return 0;
}
