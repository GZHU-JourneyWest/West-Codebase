if (Month<=2)  // 使输入符合人性也符合公式 
{	
	Month=Month+12;
	Year--;
} 
Week=(Day+2*Month+3*(Month+1)/5+Year+Year/4-Year/100+Year/400+1)%7;
// 0-6 表示 星期日到星期六
