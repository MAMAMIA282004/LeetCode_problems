#include <iostream>
using namespace std;
const int no_of_chars = 26;
string findSubString(string str, string pat)
{
      int len1 = str.length();
      int len2 = pat.length();
      // التحقق مما إذا كان طول السلسلة أقل من طول النمط
      // إذا كان الطول أقل، فلا يوجد نافذة من هذا النوع
      if (len1 < len2) {
            cout << "لا توجد نافذة متاحة";
            return "";
      }
      int hash_pat[no_of_chars] = { 0 };
      int hash_str[no_of_chars] = { 0 };
      // تخزين حدوث الحروف في النمط
      for (int i = 0; i < len2; i++)
            hash_pat[pat[i] - 'a']++;
      int start = 0, start_index = -1, min_len = INT_MAX;
      int count = 0; // عدد الحروف
      // البدء في مسح السلسلة
      for (int j = 0; j < len1; j++) {
            // حساب حدوث الحروف في السلسلة
            hash_str[str[j] - 'a']++;
            // إذا تطابقت الحرف في السلسلة مع الحرف في النمط، قم بزيادة العداد
            if (hash_str[str[j] - 'a'] <= hash_pat[str[j] - 'a'])
                  count++;
                  // إذا تطابقت جميع الحروف
            if (count == len2) {
                  // محاولة تقليل حجم النافذة
                  while (hash_str[str[start] - 'a'] > hash_pat[str[start] - 'a'] || hash_pat[str[start] - 'a'] == 0) {
                        if (hash_str[str[start] - 'a'] > hash_pat[str[start] - 'a'])
                              hash_str[str[start] - 'a']--;
                        start++;
                  }
                  // تحديث حجم النافذة
                  int len_window = j - start + 1;
                  if (min_len > len_window) {
                        min_len = len_window;
                        start_index = start;
                  }
            }
      }
      // إذا لم يتم العثور على نافذة
      if (start_index == -1) {
            cout << "لا توجد نافذة متاحة";
            return "";
      }
      // إرجاع الجزء الفرعي بدءًا من start_index بطول min_len
      return str.substr(start_index, min_len);
}
int main()
{
      string str = "abcedeca";
      string pat = "ace";
      cout << findSubString(str, pat);
      return 0;
}
