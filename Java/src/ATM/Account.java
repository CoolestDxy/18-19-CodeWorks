package ATM;


public class Account {
	private String userName;
	private String password;

	public double getBalance() {
		return balance;
	}

	private double balance = 0;

	public boolean withdraw(double balance) {
		if (this.balance-balance>0&&balance>0){
			this.balance-=balance;
			return true;
		}
		return false;
	}
	public boolean deposit(double balance){
		if (balance>0) {
			this.balance += balance;
			return true;
		}
		return false;
	}

	public boolean login(String userName, String password) {
		return  (userName.equals(this.userName) && password.equals(this.password));
	}

	Account(String userName, String password) {
		this.userName = userName;
		this.password = password;
	}

	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getPassword() {
		return password;
	}
}
