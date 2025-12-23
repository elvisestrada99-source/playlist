#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Playlist {
    int id;
    string nama;
    string deskripsi;
    Playlist *next;
};

struct Lagu {
    int id;
    string judul;
    string artis;
    int durasi;
    Lagu *next;
};

struct Relasi {
    Playlist *P;
    Lagu *L;
    Relasi *next;
};
struct ListPlaylist {
    Playlist *first;
};

struct ListLagu {
    Lagu *first;
};

struct ListRelasi {
    Relasi *first;
};

void createList(ListPlaylist &LP, ListLagu &LL, ListRelasi &LR);
Playlist* createPlaylist(int id, string nama, string deskripsi);
Lagu* createLagu(int id, string judul, string artis, int durasi);
void insertPlaylist(ListPlaylist &LP, Playlist *P);
void insertLagu(ListLagu &LL, Lagu *L);
void insertRelasi(ListRelasi &LR, Playlist *P, Lagu *L);
void showPlaylist(ListPlaylist LP);
void showLagu(ListLagu LL);
void showRelasi(ListRelasi LR);
Playlist* findPlaylist(ListPlaylist LP, int id);
Lagu* findLagu(ListLagu LL, int id);
int countLaguDariPlaylist(ListRelasi LR, Playlist *P);
void deleteRelasiByPlaylist(ListRelasi &LR, Playlist *P);
bool deletePlaylist(ListPlaylist &LP, ListRelasi &LR, int idPlaylist);

#endif
