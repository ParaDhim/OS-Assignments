SYSCALL_DEFINE4(kernel_2d_memcpy, float**, mtrx1, float**, mtrx2, int, row, int ,column)
{
	float mat[row][column];
	if(__copy_from_user(mat, mat1, sizeof()))

	//if (c<0 || c==row*c)
	{
		    return -EFAULT;
	}
	if(__copy_to_user(mat2, mat, sizeof()))

	//if (r< 0 || r == r*c)
	{
		    return -EFAULT;
	}
	    //printk("sucessful");
	    return c;

}