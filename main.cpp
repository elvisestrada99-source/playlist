#include "playlistt.h"

int menu() {
    int pilih;
    cout << "\n=== MENU PLAYLIST ===\n";
    cout << "1. Tampilkan Playlist\n";
    cout << "2. Tampilkan Lagu\n";
    cout << "3. Tampilkan Relasi\n";
    cout << "4. Count Lagu dari Playlist\n";
    cout << "5. Tambah Relasi Playlist - Lagu\n";
    cout << "6. Hapus Playlist \n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
    cin >> pilih;
    return pilih;
}

int main() {
    ListPlaylist LP;
    ListLagu LL;
    ListRelasi LR;

    createList(LP, LL, LR);


    insertPlaylist(LP, createPlaylist(1, "Jogging Vibes", "Playlist olahraga"));
    insertPlaylist(LP, createPlaylist(2, "Romantic Hits", "Lagu romantis"));

    insertLagu(LL, createLagu(101, "Fix You", "Coldplay", 250));
    insertLagu(LL, createLagu(102, "Welcome to the Black Parade", "My Chemical Romance", 311));
    insertLagu(LL, createLagu(103, "Still Don't Know My Name", "Labrinth", 214));
    insertLagu(LL, createLagu(104, "Smells Like Teen Spirit", "Nirvana", 301));
    insertLagu(LL, createLagu(105, "Yellow", "Coldplay", 269));
    insertLagu(LL, createLagu(106, "Bohemian Rhapsody", "Queen", 354));
    insertLagu(LL, createLagu(107, "Numb", "Linkin Park", 185));
    insertLagu(LL, createLagu(108, "Counting Stars", "OneRepublic", 257));
    insertLagu(LL, createLagu(109, "Perfect", "Ed Sheeran", 263));
    insertLagu(LL, createLagu(110, "Lose Yourself", "Eminem", 326));


    insertRelasi(LR, findPlaylist(LP,1), findLagu(LL,101));
    insertRelasi(LR, findPlaylist(LP,1), findLagu(LL,104));
    insertRelasi(LR, findPlaylist(LP,2), findLagu(LL,109));

    int pilih;
    do {
        pilih = menu();
        switch (pilih) {
        case 1:
            showPlaylist(LP);
            break;
        case 2:
            showLagu(LL);
            break;
        case 3:
            showRelasi(LR);
            break;
        case 4: {
            int id;
            cout << "Masukkan ID Playlist: ";
            cin >> id;
            Playlist *P = findPlaylist(LP, id);
            if (P)
                cout << "Jumlah lagu pada playlist '" << P->nama << "': "
                     << countLaguDariPlaylist(LR, P) << endl;
            else
                cout << "Playlist tidak ditemukan\n";
            break;
        }
        case 5: {
            int idP, idL;
            showPlaylist(LP);
            cout << "Masukkan ID Playlist: ";
            cin >> idP;

            showLagu(LL);
            cout << "Masukkan ID Lagu: ";
            cin >> idL;

            Playlist *P = findPlaylist(LP, idP);
            Lagu *L = findLagu(LL, idL);

            if (P && L) {
                insertRelasi(LR, P, L);
                cout << "Relasi berhasil ditambahkan\n";
            } else {
                cout << "Playlist atau Lagu tidak ditemukan\n";
            }
            break;
        }
        case 6: {
            int idP;
            showPlaylist(LP);
            cout << "Masukkan ID Playlist yang akan dihapus: ";
            cin >> idP;

            bool ok = deletePlaylist(LP, LR, idP);
            if (ok) cout << "Playlist berhasil dihapus. Relasi terkait juga ikut terhapus.\n";
            else    cout << "Gagal: ID Playlist tidak ditemukan.\n";
            break;
        }
        }
    } while (pilih != 0);

    return 0;
}
