# UDM_08 – Lập trình ứng dụng Chat (GUI) via TCP

## Mô tả

Dự án xây dựng **ứng dụng chat sử dụng giao thức TCP** với **giao diện đồ họa (GUI)**.
Toàn bộ các chức năng của chương trình được thực hiện thông qua GUI.

## Chức năng

* Toàn bộ chức năng liên quan đến ứng dụng đều thực hiện qua GUI

## Cấu trúc dự án

Ở **thư mục gốc** repo chỉ giữ đúng các phần chính (đúng format bản gốc):

* **Code:** Mã nguồn chương trình *(CMake, preset VS Code, `.clangd` nằm trong `Code/`)*  
* **DOCX:** Báo cáo dự án  
* **PPTX:** Slide thuyết trình  
* **Extra:** Hình ảnh và tài liệu bổ sung  

*(Ngoài ra có `.gitignore` chuẩn Git ở gốc.)*

## Yêu cầu & build (Windows)

Dự án dùng **Winsock** — chỉ build trên **Windows**.

Cần cài: **CMake** (≥ 3.16) và một trong các bộ compiler sau:

* **Visual Studio 2022** (workload *Desktop development with C++*), hoặc
* **MSYS2 / MinGW-w64** (g++, thường kèm **Ninja**).

**Quan trọng:** *File → Open → Folder…* phải mở thư mục **`Code`** (nơi có `CMakeLists.txt`), **không** mở cả repo gốc nếu bạn dùng CMake trong Visual Studio / VS Code.

### Visual Studio

1. *File → Open → Folder…* → chọn thư mục **`Code`**.
2. Visual Studio nhận CMake; chọn target **server**, **client** hoặc **protocol_demo** rồi *Build*.
3. Chạy: `server.exe` / `client.exe` trong `Code/build/...` (ví dụ `Debug/` hoặc `Release/` tùy generator).

### Visual Studio Code

1. *File → Open Folder…* → chọn thư mục **`Code`**.
2. Cài **CMake Tools** và **C/C++** (gợi ý trong `Code/.vscode/extensions.json`).
3. Chọn preset **vs2022** hoặc **ninja** (`Code/CMakePresets.json`), *kit*, *Build*, *Launch Target*.
4. Clangd: sau khi configure, dùng `Code/build/compile_commands.json` (`.clangd` trong `Code/`).

### Dòng lệnh (CMake)

Trong terminal, `cd` vào **`Code`** rồi:

```text
cd Code
cmake --preset vs2022
cmake --build build --config Release
```

Hoặc Ninja + MinGW:

```text
cd Code
cmake --preset ninja
cmake --build build
```

File thực thi nằm trong `Code/build/` (Ninja) hoặc `Code/build/Release|Debug/` (generator Visual Studio).

### Chạy thử

1. Terminal 1: chạy **server** (lắng nghe cổng trong `Code/Shared/Protocol.h`, mặc định **9050**).
2. Terminal 2: chạy **client**, nhập tin nhắn.
