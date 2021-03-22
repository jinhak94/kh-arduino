package com.kh.arduino.model.service;

import java.sql.Connection;
import static com.kh.common.JDBCTemplate.*;
import com.kh.arduino.model.dao.DhtDao;
import com.kh.arduino.model.vo.Dht;

public class DhtService {
	private DhtDao dhtDao = new DhtDao();
	
	public int insertDht(Dht dht) {
		Connection conn = getConnection();
		int result = dhtDao.insertDht(conn, dht);
		if(result>0) {
			commit(conn);
		}
		else 
			rollback(conn);
		close(conn);
		return result;
	}

}
