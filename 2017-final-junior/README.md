# **2017 網際網路程式設計全國⼤賽 - 國中組決賽**

### A. 線上遊戲

* **Method 1**

  討論3個數的關係，若 $T \leq x$ 顯然答案就是 $T$ 。

  接著可以發現每 $x$ 分鐘會循環一次，前 $y$ 分鐘在打魔王，後 $x - y$ 在打小兵。

  判斷一下 $T$ 結束再哪一個區間就可以算出答案。

* **Method 2**

  直接開個陣列模擬每一分鐘發生的事情，由於 $T \leq 10^3$ 很小所以不會 $TLE$ 。




### B. 密密⿇⿇密碼鎖

​	這題相當簡單，但是不知道為神麼賽中很少人過...

​	枚舉每一種密碼的可能 $for\;i = 100000 \rightarrow 999999$ 。

​	檢查 $i$ 是否每一位都不一樣，再計算和當前密碼的差距。

​	最後再把差距為最小值的那些密碼印出來。



### C. 測試資料系統

​	照著題目敘述把檔案系統建成一棵樹，每個操作就在樹上走。

​	 $rm$ 系列為刪除節點，刪除的時候要判斷節點型態是否符合，以及是否有子節點。

​	$mkdir, \;touch $為增加節點，要檢查是否已經存在。

​	$ls$ 為 $DFS$ 遍歷子樹到深度 $L$ 以內的節點。

​	可以參考我的節點結構。

```c++
struct Node {
    Node (int type, string name) {
        this->type = type;
        this->name = name;
    }
    string name;
    int type;
    vector<Node*> arr;
};
```



### D. 發獎品

​	仔細讀題目可以發現**最多只有⼋種未知價值的獎品**，且 $a_{i} \leq 10$ 。

​	我們只要把未知數的每一種可能都試一遍，看看有沒有符合要求就解決了。

​	算起來量級大概 $10 ^ 8$ 不會 $TLE$ 。



### E. 乘法問題

​	我們可以對於每一個質數分開來做前綴合，由於 $a_{i} \le 100$ 所以質數不會太多個。

​	接著我們枚舉右界 $R$，然後動態維護每個質數的左界 $L_i$ 最右可以到哪。

​	令 $L = max(L_i)$ ，則 $[1, R] \rightarrow [L, R]$ 都是合法的區間。



### F. ⽔題

​	$ans = \left | k - (n-k) \right |$



### G. 發氣球

​	開個陣列紀錄每一隊目前過那幾題，第一次過的話就給他氣球。