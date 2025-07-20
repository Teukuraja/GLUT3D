# GLUT3D — Kumpulan Objek Geometri 3D dengan OpenGL & FreeGLUT

Proyek ini berisi berbagai contoh objek geometri tiga dimensi (3D) yang divisualisasikan menggunakan bahasa pemrograman C, OpenGL, dan FreeGLUT.  
Setiap objek dapat dianimasikan dan dirotasi secara otomatis.

## ✨ Fitur
- Visualisasi **Kubus 3D**, **Prisma Segitiga**, dan **Bola (Sphere)**
- Alternatif: Torus (Donat 3D), Kerucut Spiral, Bintang 3D
- Semua objek **berputar otomatis** dengan animasi smooth
- Contoh penulisan kode rapi & mudah dikembangkan

## 📦 Struktur Folder
GLUT3D/
├── Script_titik.c # Script utama (ubah-ubah isi dengan contoh objek)
├── FreeGLUT-MinGW/ # Folder library FreeGLUT (include, lib, bin)
├── README.md # File ini
└── ... (file pendukung lain)\


##  Cara Menjalankan (Windows + MinGW + FreeGLUT)
1. **Clone repo atau download zip**
2. Buka terminal di folder proyek
3. Compile:
g++ Script_titik.c -o titik.exe -IFreeGLUT-MinGW\freeglut\include -LFreeGLUT-MinGW\freeglut\lib -lfreeglut -lopengl32 -lglu32 -lm

4. Jalankan:
.\titik.exe
5. Jika butuh file `freeglut.dll`, copy dari `bin` ke folder `.exe`.

## 🧑‍💻 Credits
- OpenGL & FreeGLUT
- Contoh kode & template oleh [Teukuraja](https://github.com/Teukuraja)  

## 📚 Lisensi
MIT License (bebas digunakan & dikembangkan)
