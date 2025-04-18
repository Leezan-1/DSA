Here’s a **Beginner-Friendly Neovim Cheat Sheet** 🧠🚀  
Organized into sections for **Navigation, File Management, Editing, Search, Windows/Tabs, Terminal, and C++ workflow**.

---

# 📝 **Neovim Cheat Sheet for Beginners**

---

## 📂 **File Management**

| Action                  | Command                    |
|-------------------------|----------------------------|
| Open file               | `:e filename`              |
| Open file in new tab    | `:tabe filename`           |
| Save file               | `:w`                       |
| Save as                 | `:w newname`               |
| Quit                    | `:q`                       |
| Save & quit             | `:wq` or `ZZ`              |
| Quit without saving     | `:q!`                      |
| Create file             | `:e newfile.cpp`           |
| Delete file             | `:!rm filename.cpp`        |
| Create folder           | `:!mkdir foldername`       |

---

## 🔀 **Basic Navigation**

| Move                     | Command        |
|--------------------------|----------------|
| Left / Down / Up / Right | `h / j / k / l`|
| Line start / end         | `0 / $`        |
| Word forward / back      | `w / b`        |
| Start / End of file      | `gg / G`       |
| Scroll half-page         | `Ctrl + d / u` |
| Jump to line             | `:linenumber`  |

---

## 🛠️ **Editing Basics**

| Action                  | Command            |
|-------------------------|--------------------|
| Enter insert mode       | `i`                |
| Append after cursor     | `a`                |
| New line below/above    | `o / O`            |
| Delete char / line      | `x / dd`           |
| Delete word             | `dw`               |
| Undo / Redo             | `u / Ctrl + r`     |
| Copy line (yank)        | `yy`               |
| Paste below             | `p`                |
| Replace one char        | `r<char>`          |
| Visual select (char)    | `v`                |
| Visual select (line)    | `V`                |
| Replace word            | `:%s/old/new/g`    |

---

## 🔎 **Searching**

| Action                        | Command           |
|-------------------------------|-------------------|
| Search forward                | `/word`           |
| Search backward               | `?word`           |
| Next / Previous result        | `n / N`           |
| Search & replace (entire file)| `:%s/foo/bar/g`   |

---

## 🪟 **Splits & Tabs**

| Action                  | Command                |
|-------------------------|------------------------|
| Vertical split          | `:vsplit` or `:vsp`    |
| Horizontal split        | `:split` or `:sp`      |
| Move between splits     | `Ctrl + w` + `h/j/k/l` |
| Open new tab            | `:tabnew filename`     |
| Next / Previous tab     | `:tabn / :tabp`        |
| Close current tab       | `:tabclose`            |

---

## 💻 **Terminal Mode**

| Action                  | Command          |
|-------------------------|------------------|
| Open terminal           | `:term`          |
| Exit terminal insert    | `Ctrl + \` then `Ctrl + n` |
| Close terminal          | `exit` or `Ctrl + d` |

---

## 🧠 **Useful Ex Commands**

| Action                  | Command               |
|-------------------------|-----------------------|
| Show line numbers       | `:set number`         |
| Disable line numbers    | `:set nonumber`       |
| Syntax highlight on/off | `:syntax on` / `off`  |
| Show hidden chars       | `:set list`           |

---

## ⚙️ **C++ Workflow**

| Action                  | Command                                               |
|-------------------------|-------------------------------------------------------|
| Compile C++             | `:!g++ filename.cpp -o output`                        |
| Run C++                 | `:!./output`                                          |
| Compile & Run together  | `:!g++ filename.cpp -o out && ./out`                 |
| Run in terminal split   | `:vsp \| term ./output`                               |

---

## 🔌 **Plugin-Related (Optional)**

If using plugins like **Telescope**, **NvimTree**, or **Lualine**:

| Action                  | Command                        |
|-------------------------|--------------------------------|
| Open Telescope (files)  | `<leader>ff`                   |
| Open file explorer      | `:NvimTreeToggle`              |
| Fuzzy find in file      | `<leader>fg`                   |

---

## 🧭 **Cheat Sheet Symbols**

- `:` → Command mode (press `:` first)
- `!` → Run external shell command
- `<leader>` → Usually `\` or set by user
- `Ctrl` → Hold Ctrl + key (e.g., `Ctrl + w`)

---

Let me know if you want a **printable version**, **custom keybindings**, or if you're using a plugin manager like `lazy.nvim` or `packer.nvim`.