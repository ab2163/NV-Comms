#include <thread>
#include "stdexec/include/exec/static_thread_pool.hpp"
#include "stdexec/include/stdexec/execution.hpp"
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

  stdexec::sender auto mysender =
  stdexec::then(
    stdexec::then(
      stdexec::bulk(
        stdexec::then(
          stdexec::then(
            stdexec::bulk(
              stdexec::then(
                stdexec::then(
                  stdexec::bulk(
                    stdexec::then(
                      stdexec::then(
                        stdexec::bulk(
                          stdexec::then(
                            stdexec::then(
                              stdexec::bulk(
                                stdexec::then(
                                  stdexec::then(
                                    stdexec::bulk(
                                      stdexec::then(
                                        stdexec::then(
                                          stdexec::bulk(
                                            stdexec::then(
                                              stdexec::then(
                                                stdexec::bulk(
                                                  stdexec::then(
                                                    stdexec::then(
                                                      stdexec::bulk(
                                                        stdexec::then(
                                                          stdexec::then(
                                                            stdexec::bulk(
                                                              stdexec::then(
                                                                stdexec::then(
                                                                  stdexec::bulk(
                                                                    stdexec::schedule(sched),
                                                                    stdexec::par_unseq, ARR_SZ,
                                                                    [&](int ind) { count[ind]++; }
                                                                  ),
                                                                  [&]() {
                                                                    for (int ind = 0; ind < ARR_SZ; ind++) {
                                                                      std::cout << count[ind] << " ";
                                                                    }
                                                                  }
                                                                ),
                                                                []() { std::cout << "\n"; }
                                                              ),
                                                              stdexec::par_unseq, ARR_SZ,
                                                              [&](int ind) { count[ind]++; }
                                                            ),
                                                            [&]() {
                                                              for (int ind = 0; ind < ARR_SZ; ind++) {
                                                                std::cout << count[ind] << " ";
                                                              }
                                                            }
                                                          ),
                                                          []() { std::cout << "\n"; }
                                                        ),
                                                        stdexec::par_unseq, ARR_SZ,
                                                        [&](int ind) { count[ind]++; }
                                                      ),
                                                      [&]() {
                                                        for (int ind = 0; ind < ARR_SZ; ind++) {
                                                          std::cout << count[ind] << " ";
                                                        }
                                                      }
                                                    ),
                                                    []() { std::cout << "\n"; }
                                                  ),
                                                  stdexec::par_unseq, ARR_SZ,
                                                  [&](int ind) { count[ind]++; }
                                                ),
                                                [&]() {
                                                  for (int ind = 0; ind < ARR_SZ; ind++) {
                                                    std::cout << count[ind] << " ";
                                                  }
                                                }
                                              ),
                                              []() { std::cout << "\n"; }
                                            ),
                                            stdexec::par_unseq, ARR_SZ,
                                            [&](int ind) { count[ind]++; }
                                          ),
                                          [&]() {
                                            for (int ind = 0; ind < ARR_SZ; ind++) {
                                              std::cout << count[ind] << " ";
                                            }
                                          }
                                        ),
                                        []() { std::cout << "\n"; }
                                      ),
                                      stdexec::par_unseq, ARR_SZ,
                                      [&](int ind) { count[ind]++; }
                                    ),
                                    [&]() {
                                      for (int ind = 0; ind < ARR_SZ; ind++) {
                                        std::cout << count[ind] << " ";
                                      }
                                    }
                                  ),
                                  []() { std::cout << "\n"; }
                                ),
                                stdexec::par_unseq, ARR_SZ,
                                [&](int ind) { count[ind]++; }
                              ),
                              [&]() {
                                for (int ind = 0; ind < ARR_SZ; ind++) {
                                  std::cout << count[ind] << " ";
                                }
                              }
                            ),
                            []() { std::cout << "\n"; }
                          ),
                          stdexec::par_unseq, ARR_SZ,
                          [&](int ind) { count[ind]++; }
                        ),
                        [&]() {
                          for (int ind = 0; ind < ARR_SZ; ind++) {
                            std::cout << count[ind] << " ";
                          }
                        }
                      ),
                      []() { std::cout << "\n"; }
                    ),
                    stdexec::par_unseq, ARR_SZ,
                    [&](int ind) { count[ind]++; }
                  ),
                  [&]() {
                    for (int ind = 0; ind < ARR_SZ; ind++) {
                      std::cout << count[ind] << " ";
                    }
                  }
                ),
                []() { std::cout << "\n"; }
              ),
              stdexec::par_unseq, ARR_SZ,
              [&](int ind) { count[ind]++; }
            ),
            [&]() {
              for (int ind = 0; ind < ARR_SZ; ind++) {
                std::cout << count[ind] << " ";
              }
            }
          ),
          []() { std::cout << "\n"; }
        ),
        stdexec::par_unseq, ARR_SZ,
        [&](int ind) { count[ind]++; }
      ),
      [&]() {
        for (int ind = 0; ind < ARR_SZ; ind++) {
          std::cout << count[ind] << " ";
        }
      }
    ),
    []() { std::cout << "\n"; }
  );
  
  stdexec::sync_wait(mysender);
  
  return 0;
}
