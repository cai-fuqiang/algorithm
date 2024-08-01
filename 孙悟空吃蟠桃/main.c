#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define __weak __attribute((weak))
#define BUG()		abort()
#define BUG_ON(_cond)    do { if ((_cond)) BUG(); }while(0)

#define pr_deb(...)   printf( __VA_ARGS__)

typedef unsigned int u32;

int peach_each_tree_arr[10240];
u32 tree_num = 0;
u32 peach_num_max = 0;

char peach_num_in_each_tree[10240];
char peach_num_in_each_tree_tmp[10240];
char go_home_time_param[16];

int go_home_time;

int get_min_eat_one_time(int tree_num, int go_home_time)
{
        
}

size_t get_int_arr_from_str_arr(int *dst_int_arr, size_t dst_size, char *src_str_arr, size_t src_size)
{
        char tmp_buf[16];
        char *p;
        int i;
        char *pos = src_str_arr;
        char *end = src_str_arr + src_size;
        int ret = 0;
        int num_tmp;
	size_t dst_cur_size = 0;

        while (1) {
                ret = sscanf(pos, "%s %*[^\n]\n",  &tmp_buf);
                if (ret != 1) {
                        ret = sscanf(pos, "%s\n", &tmp_buf);
                        if (ret != 1) {
                                break;
                        }
                }
                pos = pos + strlen(tmp_buf) + 1;
                num_tmp = atoi(tmp_buf);
                BUG_ON(num_tmp < 0);

		BUG_ON(dst_cur_size == dst_size);
		if (num_tmp > peach_num_max) {
			peach_num_max = num_tmp;
		}
                dst_int_arr[dst_cur_size++] = num_tmp;

        }
	
	return dst_cur_size;
}

int get_info_from_stdin()
{
	char *p = NULL;
	int tmp;
        p = fgets(peach_num_in_each_tree, sizeof(peach_num_in_each_tree), stdin);

	BUG_ON(!p);
	tree_num = get_int_arr_from_str_arr(peach_each_tree_arr, 10240, 
			peach_num_in_each_tree, sizeof(peach_num_in_each_tree));

        pr_deb("tree num param (%s) tree num (%d)\n", peach_num_in_each_tree, tree_num);
        p = fgets(go_home_time_param, sizeof(go_home_time_param), stdin);

	BUG_ON(!p);

	tmp = get_int_arr_from_str_arr(&go_home_time, 1, go_home_time_param, sizeof(go_home_time_param));

	pr_deb("go_home_time(%d)\n ", go_home_time);
	return 0;
}

void __weak print_int_arr_info(int *dst, size_t size)
{
	int i = 0;
	for (i = 0; i < size; i++) {
		pr_deb("[%d]:%d ", i, dst[i]);
	}
	pr_deb("size(%d)\n", size);
	pr_deb("\n");
}

bool check_eat_complete(int num)
{
	
}
int get_min_eat_number(int *peach_tree_arr, size_t tree_num, int go_home_time)
{
	int last_min_num;
	int min = 0;
	int max = peach_num_max;
	int mid = 0;

	if (go_home_time < tree_num) {
		return -1;
	}

	if (go_home_time == tree_num) {
		return peach_num_max;
	}

	while (min != max) {
		mid = (min + max) / 2;
		check_eat_complete(mid);
	}
}

int main()
{
        get_info_from_stdin();
	pr_deb("print peach_each_tree_arr\n");
	print_int_arr_info(peach_each_tree_arr, tree_num);
}
