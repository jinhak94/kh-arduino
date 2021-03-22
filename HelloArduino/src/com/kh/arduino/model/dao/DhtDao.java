package com.kh.arduino.model.dao;

import static com.kh.common.JDBCTemplate.close;

import java.io.FileReader;
import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Properties;

import com.kh.arduino.model.vo.Dht;

public class DhtDao {

	private Properties prop = new Properties();
	
	public DhtDao() {
		//WEB-INF/classes가 루트임.... Build Path에서 찾는 것임.
		String fileName = "/sql/dht-query.properties";
		//절대경로
		String path = DhtDao.class.getResource(fileName).getPath();
		try {
			prop.load(new FileReader(path));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public int insertDht(Connection conn, Dht dht) {
		PreparedStatement pstmt = null;
		ResultSet rset = null;
		String sql = prop.getProperty("insertDht");
		int result = 0;
		/*
		 * 	private long no;
	private String place;
	private double humidity;
	private double celcius;
	private double heatIndex;
	private Timestamp time;
		 */
		try {
			//1.PreparedStatement객체생성(미완성쿼리 값대입)
			pstmt = conn.prepareStatement(sql);
			pstmt.setDouble(1, dht.getHumidity());
			pstmt.setDouble(2, dht.getCelcius());
			pstmt.setDouble(3, dht.getHeatIndex());
			pstmt.setTimestamp(4, dht.getTime());
			result = pstmt.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			close(rset);
			close(pstmt);
		}

		return result;
	}

}
