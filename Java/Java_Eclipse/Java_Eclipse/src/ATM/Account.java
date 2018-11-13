package ATM;

import java.time.LocalTime;

/**
 * @typename Account
 * @package ATM
 * @description Account
 * @author Hanyuu
 * @date 2018/11/12
 * @TODO TODO
 */
public class Account {
	private String userName;
	private String password;
	private double balance = 0;
	private double interest = 0.05;
	/**
	 * @return interest
	 */
	public double getInterest() {
		return interest;
	}


	/**
	 * @param interest  interest 
	 */
	public void setInterest(double interest) {
		this.interest = interest;
	}


	/**
	 * @return lastChange
	 */
	public LocalTime getLastChange() {
		return lastChange;
	}


	/**
	 * @param lastChange  lastChange 
	 */
	public void setLastChange(LocalTime lastChange) {
		this.lastChange = lastChange;
	}


	/**
	 * @param balance  balance 
	 */
	public void setBalance(double balance) {
		this.balance = balance;
	}

	private LocalTime lastChange;

	public double getBalance() {
		return balance;
	}


	public boolean withdraw(double balance) {
		if (this.balance-balance>0&&balance>0){
			this.balance-=balance;
			return true;
		}
		return false;
	}
	public boolean deposit(double balance){
		if (balance>0) {
			LocalTime temp=LocalTime.now();
			long rate=(
					temp.getSecond()-lastChange.getSecond()+
					(temp.getMinute()-lastChange.getMinute())*60+
					(temp.getHour()-lastChange.getHour())*3600
					);
			
			this.balance+=this.balance*(rate/3)*interest;
			lastChange=LocalTime.now();
			this.balance += balance;
			return true;
		}
		return false;
	}

	public boolean login(String userName, String password) {
		return  (userName.equals(this.userName) && password.equals(this.password));
	}

	Account(String userName, String password) {
		this.lastChange=LocalTime.now();
		this.userName = userName;
		this.password = MD5Util.MD5(password);
		this.interest=0.05;
		this.balance += balance;
	}

	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public void setPassword(String password) {
		this.password =MD5Util.MD5(password);
	}

	public String getPassword() {
		return password;
	}
}
