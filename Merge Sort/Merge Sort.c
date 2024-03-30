// Merge Sort
// ~ עמית מאיר שובל

#define arr_length 8 // מגדיר גודל למערך
int arr[arr_length];// יוצר מערך

void main()
{
    int i;// יצירת משתנה
    int j;// יצירת משתנה
    printf("Enter and print unsorted element");
    for( i=0 ; i<arr_length-1 ; i++)// מעבר על כל איברי המערך
    {
        scanf("%d",%arr[i]);// קלט מהמשתמש לתוך המערך 
        printf("%d", arr[i]);// בדפסה של הקלט הקודם
    }

    merge_sort(0,arr_length-1);// יצירת פונקציה לסידור המערך המקבלת מאיפה להתחיל ועד לאן
    printf("sorted array: \n")
    for(i=0 ; i<arr_length-1 ; i++)
    {
        printf("%d \t",arr[i]);// הדפסה של המערך המסודר
    }
}

merge_sort(int low, int high)
// low = 0 , high = arr_length = 7
{
    if(low != high)
    // כל עוד נמוך שונה מגבוה
    // אם גבוהה שווה לנמוך אז הגענו לקצה ולא ניתן עוד לחלק את המערך
    {
        int mid;//יצירת משתנה ביניים
        mid = (low+high)/2;// משתנה הביניים יהיה הממוצע בין המספר הגבוהה לנמוך
        merge_sort(low,mid);// קריאה חוזרת לפונקציה כדי לפצל את המערך פעם נוספת
        merge_sort(mid+1,high);// מעבר על החצי השני של המערך, על הענף השני
        merge(low,mid,high);// קריאה לפונקציית האיחוד של המערך, סידור שלו
    }
}

merge(int low, int mid, int high)
// low = 0 , high = arr_length = 7, mid = (low+high)/2

{
    int temp[arr_length];// יצירת מערך זמני
    int i = low;// הקצאה של המספר הנמוך
    int k = low;// הקצאה של המספר הנמוך לבקרה
    int j = mid + 1;

    while((i <= mid) && (j <= high)){
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];// הצבה לתוך המערך בסדר הנכון
        }
        else
        {
            temp[k++] = arr[j++];// הצבה לתוך המערך בסדר הנכון
        }
    }
    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while(j <= high)
    {
        temp[k++] = arr[j++];
    }
    for(i = low; i <= high ; i++)
    {
        arr[i] = temp[i];// מעבר על כל המערך והצבה מהמערך שסידרנו חזרה למערך המקורי
    }
}
