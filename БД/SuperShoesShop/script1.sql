CREATE DATABASE SupershoesshopBD
GO

USE [SupershoesshopBD]

SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[Footwear](
	[Footwear_id] [int] NOT NULL,
	[Footwear_name] [nchar](20) NULL,
	[supplier] [nchar](20) NULL,
	[supplier_contacts] [nchar](20) NULL,
 CONSTRAINT [PK_sweets] PRIMARY KEY CLUSTERED 
(
	[candy_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO

