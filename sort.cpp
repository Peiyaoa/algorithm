#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
const int N = 10;
int num[N] = { 9,1,2,5,6,10,1,2,6,9 };
int n;
/*
	直接插入排序
	解题思路：从第二个数开始。每次取一个数x与前面数比较，如果x比这个数大，则把这个数后移，如果比x小则把x插在这个数的后面，每次取一个数，这个数前面的数一定有序，当	取完最后一个数时，这组数据就完成了排序。
	原理：通过构建有序序列，把未排序的数在有序序列中比较，找到对应位置进行插入。
	过程描述：如有一序列{5，1，2，9，8}
		首先取第二个数 ：1 然后向前比较 1比5小 5 后移 前面没数了 把1插在5原来的位置
		第一轮插入排序后：{1，5，2，9，8}
		取第三个数：2 向前比较 2比5小 5 后移 再比较 2大于1 则把2插入在1后面
		第二轮插入排序后；{1，2，5，9，8}
		取第四个数：9 向前比较 9比5大 直接插入在5后面
		第三轮插入排序后：{1，2，5，9，8}
		取第四个数：8 向前比较 8比9小 9后移 再比较 8大于5 则把8插入在5后面
		排序结束
*/
void insert_sort()
{
	for (int i = 1; i < n; i++)
	{
		int t = num[i];
		int j;
		for (j = i -1; j >=0; j--)
		{
			if (t < num[j])
			{
				num[j+1] = num[j];
			}
			else
				break;
		}
		num[j + 1] = t;
	}
}

/*
	冒泡排序
	解题思路：每次从第一个数开始，两两相比较，把较大的数往后挪，第一轮循环把最大的数挪到0～n序列的最后面，第二轮循环把第二大的数挪到0～n-1序列的最后面，执行n轮循环后序列变为有序。
	原理：从前至后两两依次比较，大数放后面，重复n次完成排序
	过程描述：如有一序列{5，1，2，9，8}
		第一次循环5和1比较 5大于1 交换 5与2比较 5大于2交换 5与9比较 5小于9 不交换 9大于8交换
		第一轮循环后：{1，2，5，8，9}
		第二次循环1与2比较 不交换 2与5比较 不交换 5与8比较不交换
		第二轮循环后：{1，2，5，8，9}
		第三次循环1与2比较 不交换 2与5比较 不交换 
		第三轮循环后：{1，2，5，8，9}
		第四次循环1与2比较 不交换
		第四轮循环后：{1，2，5，8，9}
		排序结束
*/
void bubble_sort()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (num[j] > num[j + 1])
			{
				int t = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t;
			}
		}
	}
}
/*
	选择排序
	解题思路：每次从第i个数开始向后比较找到最小的数，再将最小的数与第i个数交换，n-1轮循环后，序列变得有序。
	原理：每次从i~n中找最小的的数放在第i个位置，重复n-1次后，序列有序。
	过程描述：如有一序列{5，1，2，9，8}
		第一次循环从{5，1，2，9，8}找到最小值1与第一个数交换
		第一轮循环后：{1，5，2，9，8}
		第二次循环从{5，2，9，8}找到最小值2与第二个数交换
		第二轮循环后：{1，2，5，9，8}
		第三次循环从{5，9，8}找到最小值5为第三个数 不交换
		第三轮循环后：{1，2，5，9，8}
		第四次循环从{9，8}找到最小值8与第四个数交换
		第四轮循环后：{1，2，5，8，9}
		排序结束
*/
void chose_sort()
{
	for (int i = 0; i < n; i++)
	{
		int mi = i;
		for (int j = i + 1; j < n; j++)
		{
			if (num[j] < num[mi])
				mi = j;
		}
		if (mi != i)
		{
			int t = num[mi];
			num[mi] = num[i];
			num[i] = t;
		}
	}
}
void quick_sort(int l, int r)
{
	if (l >= r)
		return;
	int x = num[l + r >> 1];
	int i = l - 1, j = r + 1;
	while (i < j)
	{
		do i++; while (num[i] < x);
		do j--; while (num[j] > x);
		if (i < j)
		{
			int t = num[i];
			num[i] = num[j];
			num[j] = t;
		}
	}
	quick_sort(l, j);
	quick_sort(j + 1, r);
}

int temp[N];
void merge_sort(int l, int r)
{
	if (l >= r)
		return;
	int mid = l + r >> 1;
	merge_sort(l,mid);
	merge_sort(mid + 1, r);
	int i = l, j = mid+1, k = 0;
	while (i <= mid && j <= r)
	{
		if (num[i] > num[j])
			temp[k++] = num[j++];
		else
			temp[k++] = num[i++];
	}
	while (j <= r)
	{
		temp[k++] = num[j++];
	}
	while (i <= mid)
	{
		temp[k++] = num[i++];
	}
	for (int i = l, k = 0; i <= r; i++, k++)
	{
		num[i] = temp[k];
	}
}
/*
	折半查找
	解题思路：利用循环每次找到序列中间位置，如果要找的数小于等于中间数，则把右界限移至中间位置。如果大于中间数，则把左边界移至中间位置加1。
	原理：因为序列是单调递增序列，所以右边数大于等于左边的数，如果要寻找的数大于中间位置的数，那么要找的数一定出现右边，只需要在右边寻找即可，反之一定出现在左边，也只需要在左边寻找。
	过程描述：如有一单调递增序列{1，2，2，3，4} 需查找3是否被包含其中
		第一次循环 中间位置mid=(l+r)/2=2 左界限l=1 右界限r=5
		因为要查找的数是3大于中间位置的数2
		所以左界限变为l=mid+1 l=3
		第二次循环 中间位置mid=(l+r)/2=4
		查找的数k为3等于中间位置的数返回1代表已找到
*/
int bisearch(int k)
{
	int l = 0, r = n - 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (num[mid] >= k)
		{
			r = mid;
		}
		else
			if(num[mid]<k)
			{
				l = mid + 1;
			}
	}
	if (num[r] == k)
		return 1;
	return 0;
}

/*
	折半递归查找
	解题思路：利用递归每次找到序列中间位置，如果要找的数小于等于中间数，则利用递归在左边查找。如果大于中间数，则利用递归在右边查找。
	原理：因为序列是单调递增序列，所以右边数大于等于左边的数，如果要寻找的数大于中间位置的数，那么要找的数一定出现右边，只需要在右边递归寻找即可，反之一定出现在左边，也只需要在递归左边寻找。
	过程描述：如有一单调递增序列{1，2，2，3，4} 需查找3是否被包含其中
		第一次函数调用 中间位置mid=(l+r)/2=2 左界限l=1 右界限r=5
		因为要查找的数是3大于中间位置的数2
		所以利用递归在右边查找 l=mid+1 l=3 r不变r=5
		第二次递归 中间位置mid=(l+r)/2=4
		查找的数k为3等于中间位置的数返回1代表已找到
		*/
int bisearch2(int l, int r, int k)
{
	if (num[r] == k)
		return 1;
	if (l > r)
		return 0;
	int mid = l + r >> 1;
	if (num[mid] >= k)
		return bisearch2(l, mid, k);
	else
		return bisearch2(l+1 , mid, k);
}
int main()
{
	n = 10;
	merge_sort(0,9);
	cout << bisearch2(0, 9, 5 );
	for (auto i : num)
		cout << i << ' ';
	return 0;
}
 