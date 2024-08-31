#ifndef SINGLETON_H
#define SINGLETON_H
//Overengineering much, but for science and study :D

#include <mutex>

template <typename T>
class Singleton {
public:
  Singleton(const Singleton&) = delete;
  void operator=(const Singleton&) = delete;

  static T& GetInstance() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (!m_instance) {
      m_instance.reset(new T());
    }

    return *m_instance;
  };

protected:
  Singleton() = default;
  virtual ~Singleton() = default;

private:
  static std::unique_ptr<T> m_instance;
  static std::mutex m_mutex;
};

template <typename T>
std::unique_ptr<T> Singleton<T>::m_instance = nullptr;

template <typename T>
std::mutex Singleton<T>::m_mutex;

#endif //SINGLETON_H
