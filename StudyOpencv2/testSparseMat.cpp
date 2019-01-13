#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

template <class T> void print_matrix(const SparseMat_<T>* sm) {
	SparseMatConstIterator_<T> it = sm->begin();
	SparseMatConstIterator_<T> it_end = sm->end();
	for (;  it != it_end; it++ )
	{
		const typename SparseMat_<T>::Node* node = it.node();
		cout << "( " << node->idx[0] << " ," << node->idx[1] << " ) =" << *it << endl;
	}

}


void calling_function(void) {
	int ndim = 3;
	int size[] = { 4,4,4 };
	SparseMat_<float> sm(ndim,size);
	for (int i = 0; i < 4; i++)
	{
		int idx[2];
		idx[0] = size[0] * rand();
		idx[1] = size[1] * rand();
		sm.ref(idx) += 1.0f;
	}
	print_matrix<float>(&sm);
}



//int main() {
//	
//	/*int size[] = {10,10};
//	SparseMat sm(2,size,CV_32F);
//	for (int i = 0; i < 10; i++)
//	{
//		int idx[2];
//		idx[0] = size[0] * rand();
//		idx[1] = size[1] * rand();
//		sm.ref<float>(idx) += 1.0f;
//	}
//	SparseMatConstIterator_<float> it = sm.begin<float>();
//	SparseMatConstIterator_<float> it_end = sm.end<float>();
//
//	for (;it != it_end; it++)
//	{
//		const SparseMat::Node* node = it.node();
//		printf(" (%3d,%3d) %f\n",node->idx[0],node->idx[1],*it);
//	}*/
//
//
//
//	/*const int n_mat_size = 5;
//	const int n_mat_sz[] = {n_mat_size,n_mat_size,n_mat_size};
//	Mat n_mat(3,n_mat_sz,CV_32FC1);
//
//	RNG rng;
//	rng.fill(n_mat,RNG::UNIFORM,0,1.0f);
//
//	const Mat* arrays[] = {&n_mat,0};
//	Mat my_planes[1];
//	NAryMatIterator it(arrays,my_planes);
//
//	float s = 0;
//	int n = 0;
//	for (int i = 0; i < it.nplanes; i++,it++)
//	{
//		s += sum(it.planes[0])[0];
//		n++;
//	}
//	cout << "s = " << s << " n = " << n;*/
//
//
//	calling_function();
//
//
//
//
//	int a;
//	cin >> a;
//
//}
