# Game of Life

Реализация клеточного автомата **«Игра Жизнь»** на C++ с использованием библиотеки **SDL2** для графического вывода.

---

## 📜 Правила игры

- Мир — двумерная сетка из клеток (может быть ограниченной или бесконечной).
- Каждая клетка:
  - живая (заполненная) или мёртвая (пустая);
  - имеет 8 соседей (по горизонтали, вертикали и диагоналям).
- Новое поколение рассчитывается по правилам:
  - Мёртвая клетка с **тремя** живыми соседями — оживает.
  - Живая клетка с **2–3** живыми соседями — живёт дальше.
  - Иначе — умирает (от одиночества или перенаселения).
- Игра останавливается, если:
  - Нет живых клеток;
  - Конфигурация повторяется (периодическая);
  - Конфигурация становится стабильной.

---

## 🔧 Зависимости

- [CMake](https://cmake.org/) ≥ 3.28
- Компилятор с поддержкой C++17
- [SDL2](https://libsdl.org/)

---

## 🛠 Установка SDL2

### 🐧 Linux (Ubuntu/Debian)

```bash
sudo apt install libsdl2-dev
```

### 🍎 macOS (через Homebrew)
```bash
brew install sdl2
```

### 🪟 Windows  
✅ Вариант 1: (через vcpkg)
```bash
.\vcpkg install sdl2
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts buildsystems/vcpkg.cmake
```
✅ Вариант 2: вручную

Скачайте SDL2-devel-2.x.x-VC.zip (https://github.com/libsdl-org/SDL/releases/tag/release-3.2.14)

Распакуйте в C:/libs/SDL2

Собирайте с указанием пути:

```bash
cmake .. -DSDL2DIR="C:/libs/SDL2"
```

🧱 Сборка проекта
```bash
git clone https://github.com/Cantlor/Game_of_life.git
cd game_of_life
cmake . -B bld
cmake --build bld  
```

▶️ Запуск
```bash
cd bld
./GameOfLife --rows m --cols n --fps k (m,n,k - целые положительные числа)
```


## 🎮 Управление
- **ЛКМ** — установить/удалить клетку
- **Пробел** — пауза/продолжить
- **C** — очистить поле
- **Esc** — выход

## 🖥️ Совместимость
Код протестирован на Linux (WSL/Ubuntu). Для Windows убедитесь, что SDL2 установлен и корректно подключен в CMake.

---


