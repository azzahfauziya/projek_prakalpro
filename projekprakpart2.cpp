
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;

string user[100];
string pass[100];
int akun = 0;
int kesempatan = 3;
struct book{
    int nobuku;
    string judul;
    string penulis;
    string penerbit;
    int stok;
}buku[100];
int banyak_buku = 0;
bool found;

void title();
void loadakun();
bool login();
void saveakun();
void regis();
void menu();
void input();
void databuku();
void databuku_urut();
void pinjambuku();
void mengembalikan();

int main()
{
    int p, q;
    char balik;
    system("cls");
    loadakun();
    title();
    cout << "\nWELCOME PEMUDA TERSESAT\n";
    cout << "\nApakah Sudah Memiliki akun ? \n";
    cout << "[1] sudah\n[2] belum\n=> ";
    cin >> p;

    switch (p)
    {
    case 1:
        if (login())
        {
            do
            {menu();
            cout<<"\n\napakah anda ingin balik ke menu?\n-> ";
            cin>>balik;
            } while(balik == 'y');
        }

        break;
    case 2:
        system("cls");
        cout << "Silahkan Registrasi Terlebih Dahulu\n";
        cout << "\n[1] Ya\n[2] Mager\n\n=> ";
        cin >> q;
        switch (q)
        {
        case 1:
            regis();
            do
            {menu();
            cout<<"\n\napakah anda ingin balik ke menu?\n-> ";
            cin>>balik;
            } while(balik == 'y');
            break;
        case 2:
            exit(0);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    // belum//
}

void title()
{
    system("cls");

    cout << "+==============================================+\n";
    cout << "|| PERPUSTAKAAN JALAN YG LURUS DIKIT WKWKWKWK ||\n";
    cout << "+==============================================+\n";
}

void loadakun()
{
    ifstream file("akun.txt");
    string p;
    while (getline(file, p))
    {
        int o = p.find("|+|");
        user[akun] = p.substr(0, o);
        pass[akun] = p.substr(o + 3);

        akun++;
    }
    file.close();
}

bool login()
{
    string username, password;
    title();
    loadakun();
    cout << "\nWELCOME PEMUDA TERSESAT\n";
    cout << "\nLOGIN \n";
    while (kesempatan > 0)
    {
        cout << "\nusername : ";
        cin >> username;
        cout << "password : ";
        cin >> password;
        for (int i = 0; i < akun; i++)
        {
            if (user[i] == username && pass[i] == password)
            {
                cout << "Login berhasil\n";
                system("pause");
                return true;
            }
        }
        kesempatan--;
        cout << "Username atau password yang dimasukan salah\n";
        cout << "Sisa " << kesempatan << " kali lagi untuk mencoba\n";
    }
    cout << "Kesempatan anda telah habis\n\n";

    system("pause");
    exit(0);
}

void saveakun()
{
    ofstream file("akun.txt");
    for (int i = 0; i < akun; i++)
    {
        file << user[i] << "|+|" << pass[i] << endl;
    }
    file.close();
}

void regis()
{
    string username, password;
    bool pakai = false;
    title();
    cout << "\nWELCOME PEMUDA TERSESAT\n";
    cout << "\nREGISTRASI   \n";
    while (!pakai)
    {
        cout << "\nusername : ";
        cin >> username;
        pakai = true;
        for (int i = 0; i < akun; i++)
        {
            if (user[i] == username)
            {
                cout << "Username Atau Akun Telah Digunakan\n";
                pakai = false;

                break;
            }
        }
    }

    cout << "password : ";
    cin >> password;

    while (password.length() < 6)
    {
        cout << "\nPassword minimal 6 karakter\n";
        cout << "Masukkan ulang password : ";
        cin >> password;
    }
    user[akun] = username;
    pass[akun] = password;
    akun++;
    saveakun();
    cout << "\nAkun telah dibuat\n";
    system("pause");
    login();
}

void menu()
{
    system("cls");
    title();
    int pilih;
    cout << "\nSELAMAT DATANG SILAHKAN PILIH MENU DI BAWAH INI\n";
    cout << "\n[1] LIHAT DATA BUKU\n[2] MEMINJAM BUKU\n[3] MENGEMBALIKAN BUKU\n[4] MENAMBAH BUKU\n[5] EXIT\n=>";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
        databuku();
        break;
    case 2:
        pinjambuku();
        break;
    case 3:
        mengembalikan();
        break;
    case 4:
        input();
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }
}

void input()
{
    system ("cls");
    title();
    int banyak;
    cout<<"berapa banyak buku yang ingin anda input?\n->";
    cin>>banyak;
    cout<<endl;
    for (int i = banyak_buku; i < banyak_buku+banyak; i++)
    {
        cout<<"\nmasukkan data buku ke-"<<i+1<<endl;
        cout<<"No buku\t\t: ";
        cin>>buku[i].nobuku;
        cin.ignore();
        cout<<"Judul\t\t: ";
        getline(cin,buku[i].judul);
        cout<<"Penulis\t\t: ";
        getline(cin, buku[i].penulis);
        cout<<"Stok\t\t: ";
        cin>>buku[i].stok;
    }
    cout<<"data buku berhasil diinput!";
    banyak_buku += banyak;
}

void databuku ()
{
    system("cls");
    title();
    cout<<"DATA BUKU";
    cout<<"\n==========================================================================="<<endl;
    cout<<setw(10)<<left<<"no buku"<<"|"<<setw(40)<<left<<"judul"<<"|"<<setw(20)<<left<<"penulis"<<"|"<<setw(10)<<"stok"<<endl;
    cout<<"==========================================================================="<<endl;
    for (int i = 0; i < banyak_buku; i++)
    {
         cout<<setw(10)<<left<<buku[i].nobuku<<"|"<<setw(40)<<left<<buku[i].judul<<"|"<<setw(20)<<buku[i].penulis<<"|"<<setw(10)<<buku[i].stok<<endl;
    }
    cout<<"apakah anda mau mencari buku? (y/n) : ";
    string cari;
    string judulCari;
    cin>>cari;
    if (cari == "y" || cari == "Y")
    {
        cout<<"Masukkan judul buku yang dicari : ";
        cin.ignore();
        getline(cin, judulCari);
        cout<<endl;
        found = false;
        for (int i = 0; i < banyak_buku; i++)
        {
            if (judulCari == buku[i].judul)
            {
                cout<<"======================================\n";
                cout<<"No buku : "<<buku[i].nobuku<<endl;
                cout<<"Judul buku : "<<buku[i].judul<<endl;
                cout<<"Penulis : "<<buku[i].penulis<<endl;
                cout<<"stok : "<<buku[i].stok<<endl;
                cout<<"====================================="<<endl;
                found = true;
            }
        }
        if (!found)
        {
            cout<<"Judul buku tidak ditemukan.";
        }
    }
}

void databuku_urut()
{
    int temp;
    for (int i = 0; i < banyak_buku; i++)
    {
        for (int j = 0; j < banyak_buku-i-1; j++)
        {
            if (buku[j].nobuku > buku[j+1].nobuku)
            {
                temp = buku[j].nobuku;
                buku[j].nobuku=buku[j+1].nobuku;
                buku[j+1].nobuku=temp;
            } 
        }
    }
    cout<<"DATA BUKU";
    cout<<"\n==========================================================================="<<endl;
    cout<<setw(10)<<left<<"no buku"<<"|"<<setw(40)<<left<<"judul"<<"|"<<setw(20)<<left<<"penulis"<<"|"<<setw(10)<<"stok"<<endl;
    cout<<"==========================================================================="<<endl;
    for (int i = 0; i < banyak_buku; i++)
    {
         cout<<setw(10)<<left<<buku[i].nobuku<<"|"<<setw(40)<<left<<buku[i].judul<<"|"<<setw(20)<<buku[i].penulis<<"|"<<setw(10)<<buku[i].stok<<endl;
    }
}

void pinjambuku()
{
    title();
    databuku_urut();
    string judulpinjam;
    int jumlahpinjam;
    cout<<"\nMasukkan judul buku yang ingin dipinjam : ";
    cin.ignore();
    getline(cin, judulpinjam);
    found = false;
        for (int i = 0; i < banyak_buku; i++)
        {
            if (judulpinjam == buku[i].judul)
            {
                cout<<"\nbuku ditemukan\n";
                cout<<"berapa banyak buku yang mau dipinjam? : ";
                cin>>jumlahpinjam;
                if (buku[i].stok > jumlahpinjam)
                {
                    cout<<"buku berhasil dipinjam";
                    buku[i].stok = buku[i].stok - jumlahpinjam;
                } else 
                {
                    cout<<"jumlah buku kurang";
                }
                found = true;
            }
        }
        if (!found)
        {
            cout<<"Judul buku tidak ditemukan.";
        } 
}

void mengembalikan()
{
    title();
    databuku_urut();
    string judulkembali;
    int jumlahkembali;
    cout<<"\nMasukkan judul buku yang ingin dikembalikan : ";
    cin.ignore();
    getline(cin, judulkembali);
    found = false;
        for (int i = 0; i < banyak_buku; i++)
        {
            if (judulkembali == buku[i].judul)
            {
                cout<<"berapa banyak buku yang mau dikembalikan? : ";
                cin>>jumlahkembali;
                cout<<"buku berhasil dipinjam";
                buku[i].stok = buku[i].stok + jumlahkembali;
                found = true;
            }
        }
        if (!found)
        {
            cout<<"buku tersebut bukan milik perpustakaan ini";
        }
}