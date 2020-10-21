#include "../include/model.hpp"

/* THUAT TOAN SAP XEP DU LIEU QUICK SORT */
void QuickSort(Word *arrWord, int left, int right)
{
    int i, j;
    if (left >= right) return;
    Word word;

    word = arrWord[(left + right)/2];
    i = left;
    j = right;

    do
    {
        while (stricmp(arrWord[i].key, word.key) < 0) i++;
        while (stricmp(arrWord[j].key, word.key) > 0) j--;

        if (i <= j)
        {
            std::swap(arrWord[i], arrWord[j]);
            i++;
            j--;
        }
    }while (i < j);

    if (left < j) QuickSort(arrWord, left, j);
    if (right > i) QuickSort(arrWord, i, right);
}

/* THUAT TOAN TIM KIEM NHI PHAN */
int BinarySearch(Word *arrWord, char *key, int left, int right)
{
    if (right >= left)
    {
        int mid = (right + left)/2;

        if (stricmp(key, arrWord[mid].key) == 0)   
            return mid;
        else if (stricmp(key, arrWord[mid].key) < 0)
            return BinarySearch(arrWord, key, left, mid - 1);
        else return BinarySearch(arrWord, key, mid + 1, right);
    }

    return -1;
}

/* THUAT TOAN TIM KIEM TUAN TU */
Word* LinearSearch(Word *arrWord, int length, char *key, int &length_arrResult)
{
	Word *arrTemp = new Word[length];
    length_arrResult = 0;

    for (int i = 0; i < length; i++)
    {	
    	char temp[50];
    	memset(temp, '\0', sizeof(temp));
    	strncpy(temp, arrWord[i].key, strlen(key));
    	
    	if (stricmp(key, temp) == 0)
    		arrTemp[length_arrResult++] = arrWord[i];
    }

    return arrTemp;
}

/* HAM SAP XEP */
void Sort(Word *arrWord, int length)
{
    QuickSort(arrWord, 0, length - 1);
}

/* HAM TIM KIEM DANH SACH TU PHU HOP VOI TU KHOA */
Word* Search(Word *arrWord, int length, char *key, int &length_arrResult)
{
    return LinearSearch(arrWord, length, key, length_arrResult);
}

/* HAM TIM KIEM VI TRI CUA PHAN TU */
int SearchIndex(Word *arrWord, int length, char *key)
{
	return BinarySearch(arrWord, key, 0, length - 1);
}

/* HAM CHINH SUA TU */
void Update(Word *arrWord, int length, Word newWord)
{
    int index = SearchIndex(arrWord, length, newWord.key);

    if (index == -1)
        return;
    else arrWord[index] = newWord;
}

/* HAM XOA TU */
void Delete(Word *arrWord, int length, char *key)
{
    int index = SearchIndex(arrWord, length, key);

    if (index == -1)
        return;

    strcpy(arrWord[index].key, "");
}

/* HAM LAY CHUOI TRONG FILE DATA */
char ParseString(char data[])
{
    int n = strlen(data) - 1;
    char ch = data[0];
    char temp[n] = "";

    strncat(temp, strrev(data), strlen(data) - 1);
    strrev(temp);
    temp[n] = '\0';
    strcpy(data, temp);

    return ch;
}

/* HAM DOC FILE */
void ReadData(Word *arrWord, int &length)
{
	// mo file doc
    FILE *file;
    file = fopen(FILENAME, "r");
    if (file == NULL)
        return;

    int size_buff = 255;	// so luong buff doc
    int isWord = 1, n;
    char buff[size_buff];	// luu chuoi doc duoc
    length = 0;	// kich thuoc mang bat dau = 0

    while (!feof(file))
    {
        n = 0;
        
    	// lam sach nghia truoc khi doc
        strcpy(arrWord[length].meaning, " ");

        do
        {
            if (isWord)
            {
                strcpy(buff, "");
                fgets(buff, size_buff, file);
            }
            else isWord = 1;

            switch(buff[0])
            {
                case '@':
                	// doc den tu thu 2 thi thoat ra
                    if (++n >= 2)
                    {
                        isWord = 0;
                        break;
                    }
					
					// neu la tu moi thi luu vao mang
                    if (isWord)
                    {
                        ParseString(buff);
                        
                        // kiem tra trung
                        if (length > 0 && (strlen(buff) == 0) || (SearchIndex(arrWord, length, buff) != -1))
                        {
                        	isWord = 0;
                        	break;
						}
                        
                        strcpy(arrWord[length].key, buff);
                    }
                    break;
                case '*':
                    if (isWord)
                    {
                        ParseString(buff);
                        strcpy(arrWord[length].type, buff);
                    }
                    break;
                case '-':
                    if (isWord)
                    {
                        strcat(arrWord[length].meaning, buff);
                    }
                    break;
            }

            if (isWord == 0) break;
        }while (!feof(file));

        length++;
        if (length == MAX_ARR)
            break;
    }

    fclose(file);
}

/* HAM GHI FILE */
int SaveData(Word *arrWord, int length)
{
    // mở file để ghi
    FILE *file;
    file = fopen(FILENAME, "w");
    if (file == NULL)
        return 0;

    for (int i = 0; i < length; i++)
    {
    	// neu tu khoa rong thi khong luu
    	if (strlen(arrWord[i].key) == 0)
    		continue;
    	
        fprintf(file, "@%s\n", arrWord[i].key);
        fprintf(file, "*%s\n", arrWord[i].type);

        char *meaning;
        strcpy(meaning, arrWord[i].meaning);

        char *descr = strtok(meaning, "-");
        while (descr != NULL)
        {
            if (strcmp(descr, " ") != 0)
            {
                fprintf(file, "-%s\n", descr);
            }

            descr = strtok(NULL, "-");
        }
    }

    fclose(file);
    return 1;
}
