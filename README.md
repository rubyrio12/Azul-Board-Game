# Azul Game Implementation in  C++

##### Course: COSC 1076 - Advanced Programming Techniques
Created as part of RMIT University's COSC1076, this program re-creates the classic board game Azul, making it playable on software's terminal or console. Advancements on the classic game have been programmed, including a 6x6 Tile Board, and the ability to place tiles wherever chosen (given rules permit). Advancements made individually, base game created as part of a team (including members Anh Nguyen & Mitchell Gust). 


##### Description: A C++ implementation of Azul
##### Members: 
- Ruby Rio (s3786695)

Base Game Contributors:
- Anh Nguyen (s3616128)
- Mitchell Gust (s3782095)

#### Folder Structure
- *src*: store all source files
    - *bin*: store the program and all tests
    - *obj*: temporary folder to store object files

#### Running the application
- Bash-compatible terminals only

- **Method: Manual**
    ```
    cd src && sudo make && cd bin && ./azul 
    ``` 
#### Base Game Mode
    ```
    ./azul
    ``` 
#### Advanced Mode
    ```
    ./azul --adv
    ``` 
#### Removal of Randomness
    ```
    ./azul -s <choose a seed>
    ``` 
