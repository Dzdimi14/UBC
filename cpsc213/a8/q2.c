int a;
int b;
int c;
int ret;

int q2(int i , int k, int j)     {
  int s;
  switch (i) {
    case 10:
        s = j + k;
        break;
    case 12:
        s = j - k;
        break;
    case 14:
        if (j > k) {
            s = 1;
            break;
        } else
            s = 0;
            break;
    case 16:
        if (k > j) {
            s = 1;
            break;
        } else
            s = 0;
            break;
    case 18:
        if (k == j) {
            s = 1;
            break;
        } else
            s = 0;
            break;
    default:
        s = 0;
        break;
  }
  return s;
}

int main(void) {
    ret = q2(a, b, c);
}
