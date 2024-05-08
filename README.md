# university-db
Project to test new skills in c++ development

# App

The entire application relies on basic operations available in a typical terminal database.

A minimum of C++17 is required for the application to run due to the use of **[std::sample](https://en.cppreference.com/w/cpp/algorithm/sample)** in the code and **[extract()](https://en.cppreference.com/w/cpp/container/map/extract)** in the map.

## Idea

The main reason why I chose **[std::map](https://en.cppreference.com/w/cpp/container/map)** as a container for students in the early phase of the project was the idea of ​​quickly searching for information about students because their PESEL numbers would already be sorted.

Later, there was polymorphism of objects in the database, which I solved using unique pointers.

I wrote tests for most methods using GoogleTest and TestFixtures.
