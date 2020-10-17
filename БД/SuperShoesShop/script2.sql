CREATE DATABASE SupershoesshopBD
GO

USE [SupershoesshopBD]

SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[suppliers](
	[supp_id] [int] NOT NULL,
	[supplier_name] [nchar](20) NULL,
	[supplier_conacts] [nchar](20) NULL,

 CONSTRAINT [PK_suppliers] PRIMARY KEY CLUSTERED
 (
	[supp_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Footwear](
	[Footwear_id] [int] NOT NULL,
	[Footwear_name] [nchar](20) NULL,
	supplier_id INT 
	FOREIGN KEY (supplier_id) REFERENCES dbo.suppliers (supp_id)
 CONSTRAINT [PK_s] PRIMARY KEY CLUSTERED 
(
	[Footwear_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO