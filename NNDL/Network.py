class Network(object):

    def __init__(self,sizes):
        '''
        定义了网络的模型，层数，每层的神经元个数
        '''
        self.num_layers = len(sizes)
        self.sizes = sizes
        self.bias = [np.random.randn(y,1) for y in sizes[1:]]
        self.weights = [np.random.randn(y,x) for x,y in
            zip(sizes[:-1],sizes[1:])]


    def sigmoid(z):
        '''
        激活函数z = wx+b
        '''
        return 1.0/(1.0+np.exp(-z))

    def feedforward(self,a):
        '''
        根据给定输入计算网络输出
        '''
        for b,w in zip(self.bias,self.weights):
            a = sigmoid(np.dot(w,a)+b)
        return a

    def SGD(self,training_data,epochs,mini_batch_size,eta,test_data=None):
        '''
        随机梯度下降
        '''
        if test_data:
            n_test = len(test_data)
        n = len(training_data)
        for j in xrange(epochs):
            '''
            多少轮数据的循环
            '''
            random.shuffle(training_data) '打乱数据'
            mini_batches = [
                    training_data[k:k+mini_batch_size]
                    for k in xrange(0,n,mini_batch_size)]
            for mini_batch in mini_batches:
                self.update_mini_batch(mini_batch,eta)

            if test_data:
                print "Epoch {0}: {1}/{2}".format(
                        j,self.evaluate(test_data),n_test)
            else:
                print "Epoch {0} complete".format(j)

    def update_mini_batch(self,mini_batch,eta):
        '''
        每轮迭代的计算梯度，更新权重
        '''
        nabla_b = [np.zeros(b.shape) for b in self.biases]
        nabla_w = [np.zeros(w.shape) for w in self.weights]
        for x,y in mini_batch:
            delta_nable_b,delta_nable_w = self.backprop(x,y)
            nable_b = [nb+dnb for nb,dnb in zip(nable_b,delta_nabla_b)]
            nable_w = [nw+dnw for nw,dnw in zip(nable_w,delta_nabla_w)]
            self.weights = [w-(eta/len(mini_batch))*nw
                    for w,nw in zip(self.weights,nabla_w)]
            self.bias = [b-(eta/len(mini_batch))*nb
                    for b,nb in zip(self.bias,nabla_b)]





