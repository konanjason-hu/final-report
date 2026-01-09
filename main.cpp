#include <iostream>
#include "rlutil.h"

int main() {
    int seconds;

    // 1. 初始化與輸入
    rlutil::saveDefaultColor(); // 儲存預設顏色 [cite: 167, 168]
    rlutil::cls(); // 清空螢幕 [cite: 132]
    
    std::cout << "請輸入要倒數的秒數: ";
    std::cin >> seconds;

    // 2. 倒數準備
    rlutil::hidecursor(); // 隱藏游標，讓畫面更乾淨 [cite: 180, 182]

    // 3. 倒數主迴圈
    for (int i = seconds; i >= 0; i--) {
        rlutil::cls(); // 每一秒都清空螢幕重新繪製 [cite: 133, 137]
        
        // 判斷剩餘秒數並改變顏色 [cite: 155]
        if (i > 10) {
            rlutil::setColor(rlutil::GREEN); // 大於10秒顯示綠色 [cite: 153]
        } else if (i > 5) {
            rlutil::setColor(rlutil::YELLOW); // 6-10秒顯示黃色 [cite: 154]
        } else {
            rlutil::setColor(rlutil::RED); // 5秒以下顯示紅色 [cite: 153]
        }

        // 定位到螢幕中央 (假設終端機約為 80x25) [cite: 139, 140]
        rlutil::locate(35, 12); 
        std::cout << "剩餘時間: " << i << " 秒" << std::endl;

        // 閃爍效果：若是最後5秒，短暫暫停後清空再顯示一次可模擬閃爍
        rlutil::msleep(1000); // 暫停一秒 [cite: 249, 252]
    }

    // 4. 結束處理
    rlutil::cls();
    rlutil::setColor(rlutil::LIGHTMAGENTA); // 使用淡洋紅色提示結束 [cite: 154]
    rlutil::locate(35, 12);
    std::cout << "時間到！計時結束。" << std::endl;
    
    rlutil::setConsoleTitle("Time's Up!"); // 更改視窗標題 [cite: 258, 261]
    rlutil::showcursor(); // 恢復游標顯示 [cite: 184]
    rlutil::resetColor(); // 還原預設顏色 [cite: 175, 176]
    
    rlutil::anykey("\n按任意鍵離開程式..."); // 等待按鍵結束 [cite: 258, 261]

    return 0;
}
