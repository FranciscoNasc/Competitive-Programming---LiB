bool sieve[ms];

vi fastPrime(int lim){ // best time than the other ones
	memset(sieve, 1, sizeof sieve);
	vi resp;
	resp.pb(2);
	for(int i = 3; i < lim; i+=2){
		if(sieve[i]){
			resp.pb(i);
			if(i > lim/i) continue;
			for(int j = i*i; j < lim; j+=i+i){
				sieve[j] = 0;
			}
		}	
	}
	return resp;
}

int countDivisors(ll n){
	int ans = 0;
	for(int i = 1; i <= sqrt(n); i++){
		if(n%i==0){
			ans++;
			if(n/i != i) ans++;
		}
	}
	return ans;
}


ll gcd(ll a, ll b){ 
	while(b){
		a%=b;
		swap(a,b);
	}
	return a;
}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}

ll phi[ms]; // Euller totient function

void totient(int n){
	for(int i = 1; i <= n; i++)
		phi[i] = i;
	for(int i = 2; i <= n; i++){
		if(phi[i] == i){
			phi[i] = i - 1;
			for(int j = 2*i; j<= n; j +=i){
				phi[j] = (phi[j]/i)*(i - 1);
			}
		}
	}
}


ll mod;

ll f(ll x, ll y){ // fast exponentiation
	ll res = 1;
	x = x%mod;
	while(y>0){
		if(y & 1)
			res = (res*x)%mod;
		y = y>> 1;
		x = (x*x)%mod;		
	}
	return res;
}

// matrix exponentiation
ll mod;

const int m = 30;
struct Matrix{
	ll mat[m][m];
	Matrix operator *(const Matrix &p){
		Matrix ans;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				for(int k = ans.mat[i][j] = 0; k < m; k++)
					ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] *p.mat[k][j])%mod; 		
		return ans;
	}
};

Matrix aux;

Matrix fEXP(Matrix a, ll b){
	Matrix ans;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			ans.mat[i][j] = i == j;
	while(b){
		if(b & 1) ans = ans*a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}