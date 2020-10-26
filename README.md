# Azul Game Implementation in  C++

##### Course: COSC 1076 - Advanced Programming Techniques
##### Assignment: 2
##### Description: A C++ implementation of Azul
##### Members: 
- Anh Nguyen (s3616128)
- Mitchell Gust (s3782095)
- Ruby Rio (s3786695)
#### Folder Structure
- *src*: store all source files
    - *bin*: store the program and all tests
    - *obj*: temporary folder to store object files

#### Running the application
- Require GNU Make
- Bash-compatible terminals only
- **Method 1: Automation**
    ```
    chmod +x run.sh (only need to do this once)
    ./run.sh (run the game normally)
    ./run.sh -t <filename> (engage test mode)
    ```
    
- **Method 2: Manual**
    ```
    cd src && sudo make && cd bin && ./azul && cd .. && cd ..
    ``` 