SYSCALL_DEFINE4(kernel2Dcopy, float**, mat1, float**, mat2, int, row, int ,col)
{
	float mat[row][col];
	if(__copy_from_user(mat, mat1, 3*3*sizeof(mat1[0][0])))
	{
		return -EFAULT;
	}
	if(__copy_to_user(mat2, mat, 3*3*sizeof(mat1[0][0])))
	{
		return -EFAULT;
	}
	return 0;
}