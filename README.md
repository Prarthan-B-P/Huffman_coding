# Huffman Coding Algorithm

## 📜 Description
This project implements the Huffman Coding algorithm, a widely-used technique for data compression. Huffman Coding reduces file sizes by assigning shorter binary codes to frequently occurring characters and longer codes to less frequent ones.

### The implementation includes:
- A Huffman Tree built using character frequencies.
- Encoding a text message into a compressed binary representation.
- Decoding the binary representation back into the original text.

---

## 🚀 Features
- Efficient text compression using priority queues.
- Custom binary codes for each character based on frequency.
- Two-way functionality: Encoding and Decoding.

---

## 🛠️ Tech Stack
- **Language**: C++
- **Data Structures**: Binary Trees, Priority Queues, Hash Maps

---

## 📂 File Structure
- `main.cpp`: The main implementation of the Huffman Coding algorithm.
- `README.md`: Project description and setup instructions.

---

## 🔧 How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/Prarthan-B-P/Huffman_coding.git
   ```

2. Navigate to the project directory:
   ```bash
   cd huffman-coding
   ```

3. Compile and run the program:
   ```bash
   g++ main.cpp -o huffman && ./huffman
   ```

4. Enter the message you want to compress when prompted.

---

## 📊 Example
### Input:
```bash
Enter the message you want to hash: hello world
```

### Output:
```makefile
Encoded: 101010011110011...
Decoded: hello world
```

---

## 🌟 Future Enhancements
- Add support for file compression and decompression.
- Optimize further for large datasets.
- Implement a GUI for ease of use.

---

## 🤝 Contributing
Contributions are welcome! Feel free to fork the repository and create pull requests.

---

## 📄 License
This project is licensed under the [MIT License](LICENSE).
