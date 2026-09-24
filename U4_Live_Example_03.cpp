#include <iostream>
#include <fstream>
using namespace std;

struct ImageMeta {
    int width;
    int height;
};

int main() {
    ImageMeta img1 = {1920, 1080};
    ofstream out("img.bin", ios::binary);
    out.write((char*)&img1, sizeof(ImageMeta));
    out.close();

    ImageMeta img2;
    ifstream in("img.bin", ios::binary);
    in.read((char*)&img2, sizeof(ImageMeta));
    in.close();

    cout << "== Binary Metadata Read ==" << endl;
    cout << "Resolution: " << img2.width << " x " << img2.height << endl;
    return 0;
}
