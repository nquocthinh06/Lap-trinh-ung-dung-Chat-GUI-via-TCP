# UDM_08 – Lập trình ứng dụng Chat (GUI) via TCP

## Mô tả

Dự án xây dựng **ứng dụng chat sử dụng giao thức TCP** với **giao diện đồ họa (GUI)**.
Toàn bộ các chức năng của chương trình được thực hiện thông qua GUI.

## Chức năng

* Toàn bộ chức năng liên quan đến ứng dụng đều thực hiện qua GUI

## Cấu trúc dự án

* **Code:** Mã nguồn chương trình
* **DOCX:** Báo cáo dự án
* **PPTX:** Slide thuyết trình
* **Extra:** Hình ảnh và tài liệu bổ sung

## Yêu cầu & build (Windows)

Dự án dùng **Winsock** — chỉ build trên **Windows**.

Cần cài: **CMake** (≥ 3.16) và một trong các bộ compiler sau:

* **Visual Studio 2022** (workload *Desktop development with C++*), hoặc
* **MSYS2 / MinGW-w64** (g++, thường kèm **Ninja**).

### Visual Studio

1. *File → Open → Folder…* và chọn thư mục gốc repo (có `CMakeLists.txt`).
2. Visual Studio nhận CMake; chọn target **server**, **client** hoặc **protocol_demo** rồi *Build*.
3. Chạy: mở terminal trong IDE hoặc chạy `server.exe` / `client.exe` từ thư mục build (ví dụ `build/Debug/` hoặc `build/Release/` tùy generator).

### Visual Studio Code

1. Cài extension **CMake Tools** và **C/C++** (gợi ý đã khai báo trong `.vscode/extensions.json`).
2. Mở folder repo → CMake Tools sẽ *configure* (preset **vs2022** hoặc **ninja** trong `CMakePresets.json`).
3. Chọn *kit* (MSVC hoặc GCC), *Build*, chọn *Launch Target* (ví dụ `server` rồi `client`).
4. Clangd: sau khi configure xong, file `build/compile_commands.json` dùng cho gợi ý code (`.clangd` trỏ vào thư mục `build`).

### Dòng lệnh (CMake)

```text
cmake --preset vs2022
cmake --build build --config Release
```

Hoặc với Ninja + MinGW (đặt `CMAKE_BUILD_TYPE` nếu cần):

```text
cmake --preset ninja
cmake --build build
```

File thực thi nằm trong `build/` (Ninja) hoặc `build/Release|Debug/` (Visual Studio generator).

### Chạy thử

1. Terminal 1: chạy **server** (lắng nghe cổng trong `Code/Shared/Protocol.h`, mặc định **9050**).
2. Terminal 2: chạy **client**, nhập tin nhắn.
