#include "playlistt.h"


void createList(ListPlaylist &LP, ListLagu &LL, ListRelasi &LR) {
    LP.first = NULL;
    LL.first = NULL;
    LR.first = NULL;
}

Playlist* createPlaylist(int id, string nama, string deskripsi) {
    Playlist *P = new Playlist;
    P->id = id;
    P->nama = nama;
    P->deskripsi = deskripsi;
    P->next = NULL;
    return P;
}

Lagu* createLagu(int id, string judul, string artis, int durasi) {
    Lagu *L = new Lagu;
    L->id = id;
    L->judul = judul;
    L->artis = artis;
    L->durasi = durasi;
    L->next = NULL;
    return L;
}


void insertPlaylist(ListPlaylist &LP, Playlist *P) {
    P->next = LP.first;
    LP.first = P;
}

void insertLagu(ListLagu &LL, Lagu *L) {
    L->next = LL.first;
    LL.first = L;
}

void insertRelasi(ListRelasi &LR, Playlist *P, Lagu *L) {
    if (P == NULL || L == NULL) return;

    Relasi *R = new Relasi;
    R->P = P;
    R->L = L;
    R->next = LR.first;
    LR.first = R;
}



void showPlaylist(ListPlaylist LP) {
    cout << "\n=== DATA PLAYLIST ===\n";
    Playlist *P = LP.first;
    if (P == NULL) {
        cout << "(Playlist kosong)\n";
        return;
    }
    while (P != NULL) {
        cout << "ID   : " << P->id << endl;
        cout << "Nama : " << P->nama << endl;
        cout << "Desk : " << P->deskripsi << endl;
        cout << "------------------\n";
        P = P->next;
    }
}

void showLagu(ListLagu LL) {
    cout << "\n=== DATA LAGU ===\n";
    Lagu *L = LL.first;
    if (L == NULL) {
        cout << "(Lagu kosong)\n";
        return;
    }
    while (L != NULL) {
        cout << "ID     : " << L->id << endl;
        cout << "Judul  : " << L->judul << endl;
        cout << "Artis  : " << L->artis << endl;
        cout << "Durasi : " << L->durasi << endl;
        cout << "------------------\n";
        L = L->next;
    }
}

void showRelasi(ListRelasi LR) {
    cout << "\n=== DATA RELASI PLAYLIST - LAGU ===\n";
    Relasi *R = LR.first;
    if (R == NULL) {
        cout << "(Relasi kosong)\n";
        return;
    }
    while (R != NULL) {
        cout << "Playlist : " << R->P->nama
             << " -> Lagu : " << R->L->judul
             << " (" << R->L->artis << ")\n";
        R = R->next;
    }
}



Playlist* findPlaylist(ListPlaylist LP, int id) {
    Playlist *P = LP.first;
    while (P != NULL) {
        if (P->id == id) return P;
        P = P->next;
    }
    return NULL;
}

Lagu* findLagu(ListLagu LL, int id) {
    Lagu *L = LL.first;
    while (L != NULL) {
        if (L->id == id) return L;
        L = L->next;
    }
    return NULL;
}



int countLaguDariPlaylist(ListRelasi LR, Playlist *P) {
    int count = 0;
    Relasi *R = LR.first;
    while (R != NULL) {
        if (R->P == P) count++;
        R = R->next;
    }
    return count;
}

void deleteRelasiByPlaylist(ListRelasi &LR, Playlist *P) {
    if (P == NULL) return;

    Relasi *prev = NULL;
    Relasi *cur  = LR.first;

    while (cur != NULL) {
        if (cur->P == P) {
            // hapus node relasi cur
            Relasi *del = cur;

            if (prev == NULL) {
                LR.first = cur->next;
                cur = LR.first;
            } else {
                prev->next = cur->next;
                cur = prev->next;
            }

            delete del;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

bool deletePlaylist(ListPlaylist &LP, ListRelasi &LR, int idPlaylist) {
    Playlist *prev = NULL;
    Playlist *cur  = LP.first;

    while (cur != NULL && cur->id != idPlaylist) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) return false;

    deleteRelasiByPlaylist(LR, cur);

    if (prev == NULL) {
        LP.first = cur->next;
    } else {
        prev->next = cur->next;
    }

    delete cur;
    return true;
}
