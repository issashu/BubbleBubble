#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <vector>

template <typename T>
/**
 * Manages a collection of objects, providing operations to add, remove, and
 * retrieve objects from a list.
 */
class ObjectManager {
public:
  ObjectManager(const ObjectManager&) = delete;
  ObjectManager operator=(const ObjectManager&) = delete;
  ObjectManager(const std::vector<T>& other) = delete;
  ObjectManager(std::vector<T>&& other) = delete;

 static ObjectManager* getInstance();

  /**
   * Retrieves a modifiable reference to the object at the specified index.
   *
   * @param index The index of the object to retrieve.
   * @return A reference to the object at the specified index.
   */
 T& get(size_t index) {
  return m_objects.at(index);
 }

  /**
   * Retrieves a constant reference to the object at the specified index.
   *
   * @param index The index of the object to retrieve.
   * @return A constant reference to the object at the specified index.
   */
 const T& get(size_t index) const {
  return m_objects.at(index);
 }

  /**
   * Searches for the specified value within the managed collection of objects.
   *
   * @param value The value to search for in the collection.
   * @return A pointer to the object if found, or nullptr if the object is not
   * found.
   */
 T* search(const T& value) {
  auto it = std::find(m_objects.begin(), m_objects.end(), value);
  return it != m_objects.end() ? &(*it) : nullptr;
 }

  // Method to search and get a const element
 const T* search(const T& value) const {
  auto it = std::find(m_objects.begin(), m_objects.end(), value);
  return it != m_objects.end() ? &(*it) : nullptr;
 }

  // Methods to take possession of elements or whole vector of them
 void push(const T& value) {
  m_objects.push_back(value);
 }
 void push(T&& value) {
  m_objects.push_back(std::move(value));
 }

 void unite(std::vector<T>&& other) {
  m_objects.insert(m_objects.end(), std::make_move_iterator(other.begin()), std::make_move_iterator(other.end()));
  other.clear();
 }

private:
  ObjectManager() {
   m_objects.reserve(5);
   std::once_flag m_initFlag;
 }

  static void initSingleton() {
   m_instance = new ObjectManager();
  }

  static ObjectManager* m_instance;
  static std::once_flag m_initFlag;
  std::vector<T> m_objects;
};

// Static member definitions
template <typename T>
std::once_flag ObjectManager<T>::m_initFlag;

template <typename T>
ObjectManager<T>* ObjectManager<T>::m_instance = nullptr;

template <typename T>
ObjectManager<T>* ObjectManager<T>::getInstance() {
 std::call_once(m_initFlag, []() {
        m_instance = new ObjectManager<T>();
    });

 return m_instance;
}

#endif // OBJECT_MANAGER_H